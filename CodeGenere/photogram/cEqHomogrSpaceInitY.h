// File Automatically generated by eLiSe
#include "general/all.h"
#include "private/all.h"


class cEqHomogrSpaceInitY: public cElCompiledFonc
{
   public :

      cEqHomogrSpaceInitY();
      void ComputeVal();
      void ComputeValDeriv();
      void ComputeValDerivHessian();
      double * AdrVarLocFromString(const std::string &);
      void SetXL1(double);
      void SetYL1(double);
      void SetYL2(double);


      static cAutoAddEntry  mTheAuto;
      static cElCompiledFonc *  Alloc();
   private :

      double mLocXL1;
      double mLocYL1;
      double mLocYL2;
};
