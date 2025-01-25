====== Problem_Set_I.pdf ======
Text date: [[Zettelkasten:2023:11:04|2023-11-04]] Modi date: [[Zettelkasten:2023:11:04|2023-11-04]]
@ARTIKEL  
[*] **[[../Problem_Set_I.pdf]]** 


Pages:           2


Content-Type: text/x-zim-wiki
Wiki-Format: zim 0.6
====== Problem_Set_I.pdf ======
Text date: [[Zettelkasten:2025:01:25|2025-01-25]] Modi date: [[Zettelkasten:2023:11:09|2023-11-09]]
@ARTIKEL  
**[[./Problem_Set_I.pdf]] **



{{./Problem_Set_I.pdf.avif?width=500}}

Pages:           7


Problem Set 1
Wave Equation
due date: November 23, 2022

A

NR Hydro

Solving the wave equation

In this problem set, we will consider a simple non-relativistic example and will investigate
the one-dimensional wave equation for the scalar field ϕ
2
∂ 2 ϕ(x, t)
2 ∂ ϕ(x, t)
=
c
,
∂t2
∂x2

(1)

with c = const.

(A.1)

Fully first order formulation (10 Marks)

As a first task, rewrite the wave equation (Eq. (1)) in a fully first order form by using the
auxiliary variables η = ∂t ϕ and χ = ∂x ϕ. Collect them into the state vector u = (ϕ, η, χ)
and show that the vector equation can be written as
∂t u + A∂x u = S,

(2)

where A is a matrix and S is the vector of source terms. Analyze matrix A by evaluating
its eigenvalues and eigenvectors.

(A.2)

Solving the wave equation

In the next step, please consider the following initial condition
πx

ϕ(x, 0) = esin ( L ) − 1,
2

0 ≤ x ≤ L,

(3)

with periodic boundary condition
ϕ(x, t) = ϕ(x ± L, t).

(4)

For simplicity, you should choose L = 1 = c.
Write a code to solve the system 2 numerically using
1. (15 Marks) second-order spatial finite differencing stencils and the forward Euler
method, and
2. (25 Marks) forth-order spatial finite difference and the forth-order Runge-Kutta
method.
For the spatial grid setting, you can discretize the equation in space using an N-points
grid in cell center:


1
∆x, i = 1, 2, . . . , N,
(5)
xi = i −
2
with ∆x = L/N and ui = u(xi ). Note that the time step for this hyperbolic system has
to follow the Courant-Friedrich-Levy condition
max |λi |

∆t
≤ Cmax ,
∆x
1

(6)

