Content-Type: text/x-zim-wiki
Wiki-Format: zim 0.6
====== ProblemSets_NRII_2.pdf ======
Text date: [[Zettelkasten:2025:01:25|2025-01-25]] Modi date: [[Zettelkasten:2023:12:14|2023-12-14]]
@ARTIKEL  
**[[./ProblemSets_NRII_2.pdf]] **



{{./ProblemSets_NRII_2.pdf.avif?width=500}}

Pages:           7


Problem Set 2
Relativistic Shock Tube Problem
due date: 2nd of February 2024

1D Relativistic Shock Tube
In this problem set, we follow Martı́ & Müller1 and solve the 1D relativistic shock tube
problem in flat spacetime, which is one of the standard numerical tests in special relativistic hydrodynamics. In Minkowski spacetime, the evolution equations in conservative
form can be written in vector form as
∂
∂
U + j Fj = 0.
∂t
∂x

(1)

In the finite volume formulation, the quantity uni represents the cell average of u centered
in xi
Z xi+1/2
1
n
ui =
u(x, tn )dx,
(2)
∆x xi−1/2
where xi±1/2 = xi ± 21 ∆x the locations of cell boundary. Hence we can write the equations
as
Fi+1/2 − Fi−1/2
(3)
∂t ui = −
,
∆x
where the fluxes Fi±1/2
evaluated
at the cell boundaries such that the total quantity

 are
R xN
PN
∂t x1 u(x)dx = ∂t ∆x i=1 ui = −(FN +1/2 − F1/2 ) depends only on the flux through
the boundaries of the domain.
In our example, the state vector U = (D, Si , τ ) is defined by
D = ρW,
Si = ρhW 2 vi ,
τ = ρhW 2 − p − D,

(4)


and the flux vectors Fj = FDj , FSji , Fτj are given by
FDj = Dv j ,
FSji = Si v j + pδij ,

(5)

Fτj = (τ + p) v j ,
where ρ and p are rest mass density and pressure respectively, h = 1 + ϵ + P/ρ is the
specific enthalpy, ϵ is the specific internal energy, v i = ui /u0 are the components of the
three-velocity of the fluid, and W = u0 = √ 1 i is the Lorentz factor.
1−v vi

The system is closed by an equation of state (EOS) given in form p = P (ρ, ϵ). The
characteristic velocities for this system is given by
λi0 = v i ,
(1 − c2s )v i ± cs
i
λ± =
1

p
(1 − v 2 )[1 − v 2 c2s − (1 − c2s )(v i )2 ]
,
1 − v 2 c2s

https://link.springer.com/article/10.12942/lrr-2003-7

1

(6)

