/////////////////////////////////////////////////////////////////////////
//
// Merlin C++ Class Library for Charged Particle Accelerator Simulations
//
// Class library version 3 (2004)
//
// Copyright: see Merlin/copyright.txt
//
// Last CVS revision:
// $Date: 2004/12/13 08:38:51 $
// $Revision: 1.2 $
//
/////////////////////////////////////////////////////////////////////////

#ifndef EMField_h
#define EMField_h 1

#include "merlin_config.h"
#include "Space3D.h"

/**
* Represents an electro-magnetic field region. The field
* is defined in a implicit rectangular coordinate frame
* (x,y,z).
*/
class EMField
{
public:

	/**
	* Virtual destructor.
	*/
	virtual ~EMField ();

	/**
	* Returns the magnetic field at the point x and time t.
	* @param[in] x The location of the particle.
	* @param[in] t The time when the force is applied.
	* @return A Vector3D containing the magnetic field.
	*/
	virtual Vector3D GetBFieldAt (const Point3D& x, double t = 0) const = 0;

	/**
	* Returns the electric field at the point x and time t
	* @param[in] x The location of the particle.
	* @param[in] t The time when the force is applied.
	* @return A Vector3D containing the electric field.
	*/
	virtual Vector3D GetEFieldAt (const Point3D& x, double t = 0) const = 0;

	/**
	* Returns the force due to this field on a particle of
	* charge q with position x and velocity v at time t.
	* @param[in] x The location of the particle.
	* @param[in] v The velocity of the particle.
	* @param[in] q The charge of the particle.
	* @param[in] t The time when the force is applied.
	* @return A Vector3D containing the force on a particle of charge q.
	*/
	virtual Vector3D GetForceAt (const Point3D& x, const Vector3D& v, double q, double t = 0) const;
};

#endif
