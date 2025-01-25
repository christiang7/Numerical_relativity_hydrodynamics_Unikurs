Content-Type: text/x-zim-wiki
Wiki-Format: zim 0.6
====== Problem_Method_of_Lines.pdf ======
Text date: [[Zettelkasten:2025:01:25|2025-01-25]] Modi date: [[Zettelkasten:2023:11:26|2023-11-26]]
@ARTIKEL  
**[[./Problem_Method_of_Lines.pdf]] **



{{./Problem_Method_of_Lines.pdf.avif?width=500}}

Pages:           3


Problem Set 1
Method of Lines
due date: May 12, 2023

A

NR BHs

Finite difference on a non-uniform grid

Consider a ”logarithmic” mesh where the grid spacing increases with x, i.e.
xi = xi−1 + h,

xi+1 = xi + rh,

(1)

where r > 1 is a fixed ratio and h is the grid spacing between xi−1 and xi . This kind
of grid is commonly used in core-collapse simulation to reduce the computation cost by
using a coarser grid outside the star.

(A.1)
Derive the finite difference approximation for u′ (xi ) using the three-point stencil
(u(xi−1 ), u(xi ), u(xi+1 )). Show that your approximation is second order accurate.

(A.2)
Derive the finite difference approximation for u′′ (xi ) using the three-point stencil
(u(xi−1 ), u(xi ), u(xi+1 )). Show that your approximation is only first order accurate.

B

The Advection Equation

Consider the 1D Advection equation with periodic boundary conditions;
∂u
∂u
=c ,
∂t
∂x

0 < x < 1,

u(0, t) = u(1, t),

(2)

where we set c = 1.

(B.1)
Show that the solution to [2] for arbitrary (compatible) initial data u(x, 0) = f (x) can be
written as:
u(x, t) = f (x + ct).
(3)

(B.2)
We will proceed to solve this using a variety of discretization methods. For each of the
following, use a uniform grid with N grid-points:
xi =

i
,
N

i = 0, . . . , N − 1.

Additionally, let us use the initial data:
1

(4)

