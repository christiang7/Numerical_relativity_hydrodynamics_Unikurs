Content-Type: text/x-zim-wiki
Wiki-Format: zim 0.6
====== Numerical_relativity_simulations_of_binary_neutron_stars_-_1104.4751.pdf ======
Text date: [[Zettelkasten:2025:01:25|2025-01-25]] Modi date: [[Zettelkasten:2023:12:21|2023-12-21]]
@ARTIKEL  
**[[./Numerical_relativity_simulations_of_binary_neutron_stars_-_1104.4751.pdf]] **



{{./Numerical_relativity_simulations_of_binary_neutron_stars_-_1104.4751.pdf.avif?width=500}}

Pages:           30


Numerical relativity simulations of binary neutron stars
Marcus Thierfelder,∗ Sebastiano Bernuzzi,† and Bernd Brügmann‡

arXiv:1104.4751v3 [gr-qc] 11 Aug 2011

Theoretical Physics Institute, University of Jena, 07743 Jena, Germany
(Dated: October 30, 2018)
We present a new numerical relativity code designed for simulations of compact binaries involving
matter. The code is an upgrade of the BAM code to include general relativistic hydrodynamics and
implements state-of-the-art high-resolution-shock-capturing schemes on a hierarchy of mesh refined
Cartesian grids with moving boxes. We test and validate the code in a series of standard experiments
involving single neutron star spacetimes. We present test evolutions of quasi-equilibrium equal-mass
irrotational binary neutron star configurations in quasi-circular orbits which describe the late inspiral
to merger phases. Neutron star matter is modeled as a zero-temperature fluid; thermal effects can
be included by means of a simple ideal-gas prescription. We analyze the impact that the use of
different values of damping parameter in the Gamma-driver shift condition has on the dynamics
of the system. The use of different reconstruction schemes and their impact in the post-merger
dynamics is investigated. We compute and characterize the gravitational radiation emitted by the
system. Self-convergence of the waves is tested, and we consistently estimate error-bars on the
numerically generated waveforms in the inspiral phase.

I.

INTRODUCTION

Binary neutron stars (BNS) are among the most
promising sources of gravitational waves (GWs) for
ground-based interferometers of present and future generation [1–3], and are also at the origin of the powerful
electromagnetic astrophysical phenomena, in particular
short-gamma-ray-bursts (SGRBs) [4, 5]. While other aspects of BNS (and neutron star, NS) physics are certainly interesting, these two topics represent to date one
of the most exciting observational and theoretical challenge. On the one hand, the detection of GWs emitted
during the last orbits of a merger process is expected to
convey unique information about the nature of matter at
supra-nuclear densities which is largely unknown, e.g. [6].
On the other hand SGRBs are ultra-relativistic outflows
likely to be injected during the post-merger dynamics [7–
9], but neither a self-consistent model nor a simulation
are yet available to provide the conditions for the “central
engine” [10, 11].
A complete theoretical modeling of the late inspiral
and merger phase is possible only by means of numerical
relativity (NR) simulations. While BNS simulations have
a longer history, see e.g. [12–14] for recent reviews, the
first NR simulation was performed in [15], some years
before the first complete simulations of coalescing binary
black-holes (BBHs) [16–18]. Nowadays a number of NR
groups are performing BNS simulations [19–25].
Recent work investigated the evolution of irrotational,
circularized, equal and unequal mass binaries without
magnetic fields [19, 20, 26–28]. In these works the dynamics of the system, mainly dependent on the initial masses
of the stars involved, is explored in detail with particu-

∗ Electronic address: marcus.thierfelder@uni-jena.de
† Electronic address: sebastiano.bernuzzi@uni-jena.de
‡ Electronic address: bernd.bruegmann@uni-jena.de

lar attention on the final product of the merger: either
a hyper-massive-NS (HMNS) (which eventually collapses
on dynamical timescales) or a black-hole (BH) with an
accretion disk configuration resulting from a prompt collapse. The gravitational radiation emitted by the systems
has been characterized.
Electromagnetic fields in NR simulations of BNS have
been considered in [9, 21, 22, 29, 30]. Their impact on
GWs during the inspiral has been found negligible for astrophysically motivated intensities [22, 29, 30], while they
have certainly a major role in the post-merger phase for
several astrophysical scenarios like SGRBs. Up to now
electromagnetic fields have been considered in full general relativity (GR) simulations only within the framework of ideal general relativistic magneto-hydrodynamics
(GRMHD), i.e. in the limit of infinite electrical conductivity. Some efforts towards resistive GRMHD are ongoing [31].
In all cases mentioned above the studies are based
on the numerical solution of the ideal general relativistic hydrodynamics equations (GRHD), or GRMHD, coupled to some 3+1 hyperbolic formulations (BSSNOK [32–
34] or GHG [35]) of GR. Most of the NR results are
obtained with simplified treatments of the NS interior,
namely ideal gas, polytropic or piecewise polytropic equations of state (EoS). In [36] (and following works) zerotemperature (cold) “realistic” EoS are also employed.
Thermal effects are expected to be relevant in the postmerger phase. They are taken into account in an approximate way using hybrid EoS [36, 37], or in simulations
based on approximations of GR which instead focus more
on microphysical aspects (see e.g. [38–40]). The modeling of microphysics is particularly important in combination electromagnetic fields in order to model SGRBs.
Transport phenomena and neutrino physics [41–43] are
currently not included in full GR BNS simulations (see
however the very recent work in [44]).
We also mention that mixed binaries, i.e. binary system composed of a black-hole and a neutron star, are

