#define _USE_MATH_DEFINES

#include <cmath>
#include <complex>
#include <fstream>
#include <iostream>
#include <iterator>
#include <math.h>
#include <vector>

using namespace std;

vector<double> MVS(vector<double> v, double k) {
  vector<double> out(v.size());
  for (int i = 0; i < v.size(); i++)
    out[i] = v[i] * k;
  return out;
}

complex<double> cx(double x, double y) {
  complex<double> z(x, y);
  return z;
}

vector<double> addv(vector<double> v, vector<double> w) {
  vector<double> out(v.size());
  for (int i = 0; i < v.size(); i++)
    out[i] = v[i] + w[i];
  return out;
}

double idata(double x) { return exp(-2 * cos(2 * M_PI * x)); }

double RMSE(vector<double> data, vector<double> analy) {
  int N = data.size();
  double errorr = 0;
  for (int i = 0; i < N; i++) {
    errorr = errorr + pow((data[i] - analy[i]), 2);
  }
  double error = pow((errorr / N), 0.5);
  return error;
}

vector<double> SpatDeriv(vector<double> data, double h) {
  int n = 1 / h + 1;
  vector<double> d(n);
  d[0] = (data[1] - data[n - 1]) / (2 * h);
  d[n - 1] = (data[0] - data[n - 2]) / (2 * h);
  for (int i = 1; i < n - 1; i++) {
    d[i] = (data[i + 1] - data[i - 1]) / (2 * h);
  }
  return d;
}

vector<double> SpatDeriv2(vector<double> data, double h) {
  int n = 1 / h + 1;
  vector<double> d(n);
  d[0] = (-data[2] + 8 * data[1] - 8 * data[n - 1] + data[n - 2]) / (12 * h);
  d[n - 1] =
      (-data[1] + 8 * data[0] - 8 * data[n - 2] + data[n - 3]) / (12 * h);
  d[1] = (-data[3] + 8 * data[2] - 8 * data[0] + data[n - 1]) / (12 * h);
  d[n - 2] =
      (-data[0] + 8 * data[n - 1] - 8 * data[n - 3] + data[n - 4]) / (12 * h);
  for (int i = 2; i < n - 2; i++) {
    d[i] = (-data[i + 2] + 8 * data[i + 1] - 8 * data[i - 1] + data[i - 2]) /
           (12 * h);
    ;
  }
  return d;
}

vector<double> FE_STEP(vector<double> data, vector<double> ddata, double dt) {
  vector<double> ndata = addv(data, MVS(ddata, -dt));
  return ndata;
}

vector<double> RK2(vector<double> data, vector<double> ddata, double dt,
                   double h) {
  vector<double> w1 = SpatDeriv2(data, h);
  vector<double> w2 = SpatDeriv2(addv(data, MVS(w1, 0.5 * dt)), h);
  vector<double> ndata = addv(data, MVS(w2, dt));
  return ndata;
}

vector<double> RK4(vector<double> data, vector<double> ddata, double dt,
                   double h) {
  vector<double> w1 = SpatDeriv2(data, h);
  vector<double> w2 = SpatDeriv2(addv(data, MVS(w1, 0.5 * dt)), h);
  vector<double> w3 = SpatDeriv2(addv(data, MVS(w2, 0.5 * dt)), h);
  vector<double> w4 = SpatDeriv2(addv(data, MVS(w2, dt)), h);
  vector<double> ndata =
      addv(data, MVS(addv(addv(addv(w1, MVS(w2, 2)), MVS(w3, 2)), w4), dt / 6));
  return ndata;
}

vector<complex<double>> fft(vector<double> data, int N) {
  double N1 = N;
  vector<complex<double>> transf(N);
  for (int i = 0; i < N; ++i) {
    transf[i] = 0.;
  }
  for (int i = 0; i < N; ++i) {
    double i1 = i;
    for (int j = 0; j < N; ++j) {
      double j1 = j;
      transf[i] = transf[i] +
                  data[j] * exp(-2. * M_PI * cx(0., 1.) * i1 * j1 / N1) / N1;
    }
  }
  return transf;
}

vector<double> ifft(vector<complex<double>> data, int N) {
  double N1 = N;
  vector<double> itransf(N);
  for (int i = 0; i < N; ++i) {
    itransf[i] = 0.;
  }
  for (int i = 0; i < N; ++i) {
    double i1 = i;
    for (int j = 0; j < N; ++j) {
      double j1 = j;
      itransf[i] = itransf[i] +
                   real(data[j] * exp(2. * M_PI * cx(0., 1.) * i1 * j1 / N1));
    }
  }
  return itransf;
}

vector<double> specderiv(vector<double> data) {
  // Add support for odd sized vectors
  int N = data.size();
  double N1 = N;
  vector<complex<double>> transf = fft(data, N);
  vector<complex<double>> dtransf(N);
  for (int i = 0; i < N / 2; ++i) {
    double i1 = i;
    dtransf[i] = 2. * M_PI * cx(0., 1.) * i1 * transf[i];
  }
  dtransf[N / 2 - 1] = 0;
  for (int i = N / 2; i < N; ++i) {
    double i1 = i;
    dtransf[i] = 2. * M_PI * cx(0., 1.) * (i1 - N1) * transf[i];
  }
  vector<double> sder = ifft(dtransf, N);
  return sder;
}

vector<double> Evolve(vector<double> data, double dt, double h, double T) {
  int n = 1 / h + 1;
  vector<double> fdata(n);
  for (double t = 0; t < T; t = t + dt) {
    // fdata = FE_STEP(data, SpatDeriv(data, h), dt);
    fdata = RK4(data, SpatDeriv2(data, h), dt, h);
    data = fdata;
  }
  return fdata;
}

int main() {
  double h = 0.01;
  int n = 1 / h + 1;
  double dt = 0.01;
  double T = 0.7;

  int N = 100;
  double N1 = N;

  // Feel free to experiment here!

  return 0;
}