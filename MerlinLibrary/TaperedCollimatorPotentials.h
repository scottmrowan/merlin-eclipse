#include <typeinfo>
#include <iostream>

#include "AcceleratorModel.h"
#include "WakePotentials.h"
#include "AcceleratorModelConstructor.h"
#include "Drift.h"
#include "Collimator.h"

#include "BeamData.h"
#include "ParticleBunchConstructor.h"
#include "ParticleTracker.h"

#include "CollimatorWakeProcess.h"
#include "CollimatorWakePotentials.h"

#include "PhysicalUnits.h"
#include "PhysicalConstants.h"

#include "RandomNG.h"

using namespace std;
using namespace PhysicalUnits;
using namespace PhysicalConstants;
using namespace ParticleTracking;

class TaperedCollimatorPotentials:public CollimatorWakePotentials
{
public:
	double a,b;
	double* coeff;
	TaperedCollimatorPotentials(int m, double rada, double radb):CollimatorWakePotentials(m,0.,0.)
	{
		a=rada;
		b=radb;
		coeff=new double[m+1];
		for(int i=0; i<=m; i++)
		{
			coeff[i]=2*(1./pow(a,2*i)-1./pow(b,2*i));
		}
	}
	~TaperedCollimatorPotentials()
	{
		delete[] coeff;
	}
	double Wlong (double z) const
	{
		return 0;
	};
	double Wtrans (double z) const
	{
		return 0;
	};
	double Wlong (double z,int m) const
	{
		return  z>0?-(m/a)*coeff[m]/exp(m*z/a):0;
	};
	double Wtrans (double z,int m) const
	{
		return z>0?coeff[m]/exp(m*z/a):0;
	};
};

