/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2020 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
License
    This file is derivative work of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "saurelGranular.H"

// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

template<class Specie>
inline Foam::saurelGranular<Specie>::saurelGranular
(
    const Specie& sp,
    const scalar a,
    const scalar n,
    const scalar alphaCrit
)
:
    Specie(sp),
    a_(a),
    n_(n),
    alphaCrit_(alphaCrit)
{}


template<class Specie>
Foam::scalar Foam::saurelGranular<Specie>::Pi
(
    const scalar rho,
    const scalar e
) const
{
	//TODO
    //return gamma_*a_;
	NotImplemented;
	return 0;
}


template<class Specie>
Foam::scalar Foam::saurelGranular<Specie>::delta
(
    const scalar p,
    const scalar rho,
    const scalar e
) const
{
    return 0.0;
}


template<class Specie>
Foam::scalar Foam::saurelGranular<Specie>::b1
(
	const scalar alpha
) const
{
	return (1-alpha)*log(1-alpha);
}

template<class Specie>
Foam::scalar Foam::saurelGranular<Specie>::b2
(
	const scalar alpha
) const
{
	return (1+log(1-alphaCrit_))*(alpha-alphaCrit_);
}

template<class Specie>
Foam::scalar Foam::saurelGranular<Specie>::B
(
	const scalar alpha
) const
{
	if(alpha < 1 && alpha >alphaCrit_)
		return a_*pow(b1(alpha)- b1(alphaCrit_)+ b2(alpha),n_);
	return 0;
}

template<class Specie>
Foam::scalar Foam::saurelGranular<Specie>::dBdalpha
(
	const scalar alpha
) const
{
	if(alpha < 1 && alpha >alphaCrit_)
		return -a_*n_*log((1-alpha)/(1-alphaCrit_))*pow(b1(alpha)- b1(alphaCrit_)+ b2(alpha),n_-1);
	return 0;
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class Specie>
inline Foam::saurelGranular<Specie>::saurelGranular
(
    const word& name,
    const saurelGranular<Specie>& pf
)
:
    Specie(name, pf),
    a_(pf.a_),
    n_(pf.n_),
    alphaCrit_(pf.alphaCrit_)
{}


template<class Specie>
inline Foam::autoPtr<Foam::saurelGranular<Specie>>
Foam::saurelGranular<Specie>::clone() const
{
    return autoPtr<saurelGranular<Specie>>
    (
        new saurelGranular<Specie>(*this)
    );
}


template<class Specie>
inline Foam::autoPtr<Foam::saurelGranular<Specie>>
Foam::saurelGranular<Specie>::New
(
    const dictionary& dict
)
{
    return autoPtr<saurelGranular<Specie>>
    (
        new saurelGranular<Specie>(dict)
    );
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class Specie>
Foam::scalar Foam::saurelGranular<Specie>::p
(
    const scalar rho,
    const scalar e,
    const scalar T,
    const bool limit
) const
{
	//TODO
	/*
    return
        limit
      ? max((gamma_ - 1.0)*rho*e - Pi(rho, e), 0.0)
      : (gamma_ - 1.0)*rho*e - Pi(rho, e);
      */
    NotImplemented;
    return 0;
}


template<class Specie>
Foam::scalar Foam::saurelGranular<Specie>::rho
(
    const scalar p,
    const scalar T
) const
{
    NotImplemented;
    return 0;
}


template<class Specie>
Foam::scalar Foam::saurelGranular<Specie>::Gamma
(
    const scalar rho,
    const scalar e,
    const scalar T,
    const scalar Cv
) const
{
    //TODO
    //return gamma_;
    NotImplemented;
    return 0;
}


template<class Specie>
Foam::scalar Foam::saurelGranular<Specie>::cSqr
(
    const scalar p,
    const scalar rho,
    const scalar e,
    const scalar T,
    const scalar Cv
) const
{
	//TODO
	/*
    scalar h((gamma_*p + Pi(rho, e))/((gamma_ - 1.0)*max(rho, 1e-10)));
    return (h - delta(p, rho, e))*(gamma_ - 1.0);
    */
    NotImplemented;
    return 0;
}


template<class Specie>
Foam::scalar Foam::saurelGranular<Specie>::dpdv
(
    const scalar rho,
    const scalar e,
    const scalar T
) const
{
    // TODO
    // return -sqr(rho)*(gamma_ - 1.0)*e;
    NotImplemented;
    return 0;
}


template<class Specie>
Foam::scalar Foam::saurelGranular<Specie>::dpde
(
    const scalar rho,
    const scalar e,
    const scalar T
) const
{
	NotImplemented;
	//TODO
    //return (gamma_ - 1.0)*rho;
    return 0;
}


template<class Specie>
Foam::scalar Foam::saurelGranular<Specie>::dpdT
(
    const scalar rho,
    const scalar e,
    const scalar T
) const
{
    NotImplemented;
    return 0.0;
}


template<class Specie>
Foam::scalar Foam::saurelGranular<Specie>::Cp
(
    const scalar rho,
    const scalar e,
    const scalar T
) const
{
    return 0.0;
}


template<class Specie>
Foam::scalar Foam::saurelGranular<Specie>::Cv
(
    const scalar rho,
    const scalar e,
    const scalar T
) const
{
    return 0.0;
}


template<class Specie>
Foam::scalar Foam::saurelGranular<Specie>::CpMCv
(
    const scalar rho,
    const scalar e,
    const scalar T,
    const scalar CpCv
) const
{
	//TODO
    //return this->eBased_ ? (gamma_ - 1.0)*CpCv : CpCv*(gamma_ - 1.0)/gamma_;
    NotImplemented;
    return 0;
}


template<class Specie>
Foam::scalar Foam::saurelGranular<Specie>::E
(
    const scalar rho,
    const scalar e,
    const scalar T
) const
{
    //TODO
    return a_/max(rho, 1e-6);
}


template<class Specie>
Foam::scalar Foam::saurelGranular<Specie>::H
(
    const scalar rho,
    const scalar e,
    const scalar T
) const
{
    return 0;
}


template<class Specie>
Foam::scalar Foam::saurelGranular<Specie>::S
(
    const scalar p,
    const scalar T
) const
{
	//TODO:
    NotImplemented;
    /*
    scalar rho((p - gamma_*a_)/this->R()*T);
    scalar rho0((Pstd - gamma_*a_)/this->R()*Tstd);
    return this->R()*(log(rho0) - log(rho));
    */
    return 0;
}


// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //

template<class Specie>
inline void Foam::saurelGranular<Specie>::operator+=
(
    const saurelGranular<Specie>& pf
)
{
	//TODO
	NotImplemented;
	/*
    scalar Y1 = this->Y();
    Specie::operator+=(pf);

    if (mag(this->Y()) > SMALL)
    {
        Y1 /= this->Y();
        const scalar Y2 = pf.Y()/this->Y();

        //- Save thegamma_ original gamma
        scalar gamma1 = gamma_;

        gamma_ = 1.0/(Y1/(gamma_ - 1.0) + Y2/(pf.gamma_ - 1.0)) + 1.0;
        a_ =
            (gamma_ - 1.0)/gamma_
           *(
                Y1*a_*gamma1/(gamma1 - 1.0)
              + Y2*pf.a_*pf.gamma_/(pf.gamma_ - 1.0)
            );
    }
    */
}


template<class Specie>
inline void Foam::saurelGranular<Specie>::operator*=(const scalar s)
{
    Specie::operator*=(s);
}


// * * * * * * * * * * * * * * * Friend Operators  * * * * * * * * * * * * * //

template<class Specie>
inline Foam::saurelGranular<Specie> Foam::operator+
(
    const saurelGranular<Specie>& pf1,
    const saurelGranular<Specie>& pf2
)
{
    Specie sp
    (
        static_cast<const Specie&>(pf1)
      + static_cast<const Specie&>(pf2)
    );
    /*

    if (mag(sp.Y()) < SMALL)
    {
        return saurelGranular<Specie>
        (
            sp,
            pf1.a_,
            pf1.gamma_
        );
    }
    else
    {
        const scalar Y1 = pf1.Y()/sp.Y();
        const scalar Y2 = pf2.Y()/sp.Y();

        scalar gamma =
            1.0/(Y1/(pf1.gamma_ - 1.0) + Y2/(pf2.gamma_ - 1.0)) + 1.0;

        return saurelGranular<Specie>
        (
            sp,
            (gamma - 1.0)/gamma
           *(
                Y1*pf1.a_*pf1.gamma_/(pf1.gamma_ - 1.0)
              + Y2*pf2.a_*pf2.gamma_/(pf2.gamma_ - 1.0)
            ),
            gamma
        );
    }
    */
    NotImplemented;

    return saurelGranular<Specie>(
    	sp,
		pf1.a_,
		pf1.n_,
		pf1.alphaCrit_
    );
}


template<class Specie>
inline Foam::saurelGranular<Specie> Foam::operator*
(
    const scalar s,
    const saurelGranular<Specie>& pf
)
{
    return saurelGranular<Specie>
    (
        s*static_cast<const Specie&>(pf),
        pf.a_,
        pf.n_,
        pf.alphaCrit_
    );
}


template<class Specie>
inline Foam::saurelGranular<Specie> Foam::operator==
(
    const saurelGranular<Specie>& pf1,
    const saurelGranular<Specie>& pf2
)
{
    Specie sp
    (
        static_cast<const Specie&>(pf1)
     == static_cast<const Specie&>(pf2)
    );
	//TODO
	//
	// wut?
	/*
    const scalar Y1 = pf1.Y()/sp.Y();
    const scalar Y2 = pf2.Y()/sp.Y();

    // NEED TO CONFIRM
    scalar gamma =
            1.0/(Y2/(pf2.gamma_ - 1.0) - Y1/(pf1.gamma_ - 1.0)) + 1.0;
    return saurelGranular<Specie>
    (
        sp,
        (gamma - 1.0)/gamma
       *(
            Y2*pf2.a_*pf2.gamma_/(pf2.gamma_ - 1.0)
          - Y1*pf1.a_*pf1.gamma_/(pf1.gamma_ - 1.0)
        ),
        gamma
    );
    */
    NotImplemented;
    return saurelGranular<Specie> (sp,pf1.a_,pf1.n_,pf1.alphaCrit_);
}


// ************************************************************************* //
