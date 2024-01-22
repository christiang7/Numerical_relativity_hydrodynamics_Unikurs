Content-Type: text/x-zim-wiki
Wiki-Format: zim 0.6
====== Analytic_Closures_for_M1_Neutrino_Transport_1701-07027v1.pdf ======
Text date: [[Zettelkasten:2024:01:18|2024-01-18]] Modi date: [[Zettelkasten:2024:01:18|2024-01-18]]
@ARTIKEL  
[*] **[[../Analytic_Closures_for_M1_Neutrino_Transport_1701-07027v1.pdf]] **



{{../Analytic_Closures_for_M1_Neutrino_Transport_1701-07027v1.pdf.avif?width=500}}

Pages:           13


MNRAS 000, 1–13 (0000)

Preprint 22 July 2022

Compiled using MNRAS LATEX style file v3.0

Analytic Closures for M1 Neutrino Transport
E. M. Murchikova1? , E. Abdikamalov2 , T. Urbatsch3
1 TAPIR, MC 350-17, California Institute of Technology, 1200 E California Blvd., Pasadena, CA 91125, USA
2 Department of Physics, School of Science and Technology, Nazarbayev University, Astana 010000, Kazakhstan
3 Los Alamos National Laboratory, Los Alamos, NM, USA

arXiv:1701.07027v1 [astro-ph.HE] 24 Jan 2017

22 July 2022

ABSTRACT

Carefully accounting for neutrino transport is an essential component of many astrophysical studies. Solving the full transport equation is too expensive for most realistic
applications, especially those involving multiple spatial dimensions. For such cases, resorting to approximations is often the only viable option for obtaining solutions. One
such approximation, which recently became popular, is the M1 method. It utilizes the
system of the lowest two moments of the transport equation and closes the system with
an ad hoc closure relation. The accuracy of the M1 solution depends on the quality of
the closure. Several closures have been proposed in the literature and have been used
in various studies. We carry out an extensive study of these closures by comparing
the results of M1 calculations with precise Monte Carlo calculations of the radiation
field around spherically-symmetric protoneutron star models. We find that no closure
performs consistently better or worse than others in all cases. The level of accuracy a
given closure yields depends on the matter configuration, neutrino type, and neutrino
energy. Given this limitation, the maximum entropy closure by Minerbo (1978) on
average yields relatively accurate results in the broadest set of cases considered in this
work.
Key words: Hydrodynamics, Neutrinos, Radiative Transfer, Stars: Evolution, Stars:
Neutron, Stars: Supernovae: General

1

INTRODUCTION

Neutrinos play an important role in core-collapse supernovae
(CCSNe), coalescence of binary neutron stars and many
other astrophysical phenomena. Their collective behavior is
described by the distribution function that obeys the Boltzmann transport equation. The state of the radiation field
is characterized by spatial coordinates, the propagation direction (two angles), energy, and time, making the problem seven-dimensional in the most general case. Many astrophysical systems have dense and opaque central regions
surrounded by transparent low-density envelopes. Radiation
moves within the dense central regions via diffusion and,
when it leaks into the outer regions, it streams freely. The
transport equation has a parabolic character in the former
region, while in the latter region, it has a hyperbolic character (e.g., Mihalas & Mihalas 1984; Pomraning 1983). In
order to model such systems accurately, the solution techniques must handle not only the two different regimes, but
also the transition between the two. These aspects make
solving the transport equation a challenging computational

?

lena@tapir.caltech.edu

c 0000 The Authors

task. For this reason, often one has to resort to approximations and simplifications to make the problem tractable.
One way of simplifying the problem is to assume spherical or axial symmetries to reduce the number of spatial dimensions. There are many problems where such assumptions
have been employed [by Mezzacappa & Bruenn (1993a,b,c);
Yamada (1997); Rampp & Janka (2000); Liebendörfer et al.
(2005); Sumiyoshi et al. (2005) assuming 1D, by (Marek &
Janka 2009; Buras et al. 2006) using ray-by-ray and by Livne
et al. (2004); Ott et al. (2008); Brandt et al. (2011); Skinner
et al. (2016) assuming 2D]. Most realistic problems, however,
do not posses spatial symmetries. For these problems, the
transport equation has to be solved in full three dimensions.
The pioneering attempts to solve three-dimensional Boltzmann equation have been already taken (e.g., Radice et al.
2013; Sumiyoshi & Yamada 2012; Sumiyoshi et al. 2015),
yet the computational cost remains too high for solving it
in realistic scenarios.
In order to further reduce the cost, one can approximate
the Boltzmann equation either by neglecting the time dependence (steady-state solution) and/or energy dependence
(gray schemes). One of the crudest approximations to the
transport problem, the so-called leakage scheme has been

