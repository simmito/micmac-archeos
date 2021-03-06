// File Automatically generated by eLiSe
#include "general/all.h"
#include "private/all.h"
#include "cEqHomogrSpaceInitX.h"


cEqHomogrSpaceInitX::cEqHomogrSpaceInitX():
    cElCompiledFonc(1)
{
   AddIntRef (cIncIntervale("Hom1",0,8));
   AddIntRef (cIncIntervale("Hom2",8,16));
   Close(false);
}



void cEqHomogrSpaceInitX::ComputeVal()
{
   double tmp0_ = mCompCoord[6];
   double tmp1_ = tmp0_*mLocXL1;
   double tmp2_ = mCompCoord[7];
   double tmp3_ = tmp2_*mLocYL1;
   double tmp4_ = tmp1_+tmp3_;
   double tmp5_ = tmp4_+1;
   double tmp6_ = mCompCoord[0];
   double tmp7_ = tmp6_*mLocXL1;
   double tmp8_ = mCompCoord[1];
   double tmp9_ = tmp8_*mLocYL1;
   double tmp10_ = tmp7_+tmp9_;
   double tmp11_ = mCompCoord[2];
   double tmp12_ = tmp10_+tmp11_;
   double tmp13_ = (tmp12_)/(tmp5_);
   double tmp14_ = mCompCoord[15];
   double tmp15_ = mCompCoord[3];
   double tmp16_ = tmp15_*mLocXL1;
   double tmp17_ = mCompCoord[4];
   double tmp18_ = tmp17_*mLocYL1;
   double tmp19_ = tmp16_+tmp18_;
   double tmp20_ = mCompCoord[5];
   double tmp21_ = tmp19_+tmp20_;
   double tmp22_ = (tmp21_)/(tmp5_);
   double tmp23_ = mCompCoord[12];
   double tmp24_ = (tmp22_)*tmp14_;
   double tmp25_ = tmp23_-tmp24_;
   double tmp26_ = mCompCoord[9];
   double tmp27_ = (tmp13_)*tmp14_;
   double tmp28_ = tmp26_-tmp27_;
   double tmp29_ = mCompCoord[14];

  mVal[0] = ((tmp25_)*(tmp13_-mCompCoord[10])-(tmp28_)*(tmp22_-mCompCoord[13]))/((mCompCoord[8]-(tmp13_)*tmp29_)*(tmp25_)-(tmp28_)*(mCompCoord[11]-(tmp22_)*tmp29_))-mLocXL2;

}


void cEqHomogrSpaceInitX::ComputeValDeriv()
{
   double tmp0_ = mCompCoord[6];
   double tmp1_ = tmp0_*mLocXL1;
   double tmp2_ = mCompCoord[7];
   double tmp3_ = tmp2_*mLocYL1;
   double tmp4_ = tmp1_+tmp3_;
   double tmp5_ = tmp4_+1;
   double tmp6_ = mCompCoord[0];
   double tmp7_ = tmp6_*mLocXL1;
   double tmp8_ = mCompCoord[1];
   double tmp9_ = tmp8_*mLocYL1;
   double tmp10_ = tmp7_+tmp9_;
   double tmp11_ = mCompCoord[2];
   double tmp12_ = tmp10_+tmp11_;
   double tmp13_ = (tmp12_)/(tmp5_);
   double tmp14_ = mCompCoord[15];
   double tmp15_ = mCompCoord[3];
   double tmp16_ = tmp15_*mLocXL1;
   double tmp17_ = mCompCoord[4];
   double tmp18_ = tmp17_*mLocYL1;
   double tmp19_ = tmp16_+tmp18_;
   double tmp20_ = mCompCoord[5];
   double tmp21_ = tmp19_+tmp20_;
   double tmp22_ = (tmp21_)/(tmp5_);
   double tmp23_ = mCompCoord[12];
   double tmp24_ = (tmp22_)*tmp14_;
   double tmp25_ = tmp23_-tmp24_;
   double tmp26_ = mCompCoord[9];
   double tmp27_ = (tmp13_)*tmp14_;
   double tmp28_ = tmp26_-tmp27_;
   double tmp29_ = mCompCoord[14];
   double tmp30_ = mLocXL1*(tmp5_);
   double tmp31_ = ElSquare(tmp5_);
   double tmp32_ = (tmp30_)/tmp31_;
   double tmp33_ = mCompCoord[13];
   double tmp34_ = tmp22_-tmp33_;
   double tmp35_ = mCompCoord[8];
   double tmp36_ = (tmp13_)*tmp29_;
   double tmp37_ = tmp35_-tmp36_;
   double tmp38_ = (tmp37_)*(tmp25_);
   double tmp39_ = mCompCoord[11];
   double tmp40_ = (tmp22_)*tmp29_;
   double tmp41_ = tmp39_-tmp40_;
   double tmp42_ = (tmp28_)*(tmp41_);
   double tmp43_ = tmp38_-tmp42_;
   double tmp44_ = mCompCoord[10];
   double tmp45_ = tmp13_-tmp44_;
   double tmp46_ = (tmp25_)*(tmp45_);
   double tmp47_ = (tmp28_)*(tmp34_);
   double tmp48_ = tmp46_-tmp47_;
   double tmp49_ = (tmp32_)*tmp14_;
   double tmp50_ = -(tmp49_);
   double tmp51_ = mLocYL1*(tmp5_);
   double tmp52_ = (tmp51_)/tmp31_;
   double tmp53_ = (tmp52_)*tmp14_;
   double tmp54_ = -(tmp53_);
   double tmp55_ = ElSquare(tmp43_);
   double tmp56_ = (tmp5_)/tmp31_;
   double tmp57_ = (tmp56_)*tmp14_;
   double tmp58_ = -(tmp57_);
   double tmp59_ = (tmp32_)*tmp29_;
   double tmp60_ = -(tmp59_);
   double tmp61_ = (tmp52_)*tmp29_;
   double tmp62_ = -(tmp61_);
   double tmp63_ = (tmp56_)*tmp29_;
   double tmp64_ = -(tmp63_);
   double tmp65_ = (tmp12_)*mLocXL1;
   double tmp66_ = -(tmp65_);
   double tmp67_ = tmp66_/tmp31_;
   double tmp68_ = (tmp21_)*mLocXL1;
   double tmp69_ = -(tmp68_);
   double tmp70_ = tmp69_/tmp31_;
   double tmp71_ = (tmp70_)*tmp14_;
   double tmp72_ = -(tmp71_);
   double tmp73_ = (tmp67_)*tmp14_;
   double tmp74_ = -(tmp73_);
   double tmp75_ = (tmp12_)*mLocYL1;
   double tmp76_ = -(tmp75_);
   double tmp77_ = tmp76_/tmp31_;
   double tmp78_ = (tmp21_)*mLocYL1;
   double tmp79_ = -(tmp78_);
   double tmp80_ = tmp79_/tmp31_;
   double tmp81_ = (tmp80_)*tmp14_;
   double tmp82_ = -(tmp81_);
   double tmp83_ = (tmp77_)*tmp14_;
   double tmp84_ = -(tmp83_);
   double tmp85_ = -(1);
   double tmp86_ = -(tmp22_);
   double tmp87_ = -(tmp13_);

  mVal[0] = (tmp48_)/(tmp43_)-mLocXL2;

  mCompDer[0][0] = (((tmp32_)*(tmp25_)-tmp50_*(tmp34_))*(tmp43_)-(tmp48_)*(tmp60_*(tmp25_)-tmp50_*(tmp41_)))/tmp55_;
  mCompDer[0][1] = (((tmp52_)*(tmp25_)-tmp54_*(tmp34_))*(tmp43_)-(tmp48_)*(tmp62_*(tmp25_)-tmp54_*(tmp41_)))/tmp55_;
  mCompDer[0][2] = (((tmp56_)*(tmp25_)-tmp58_*(tmp34_))*(tmp43_)-(tmp48_)*(tmp64_*(tmp25_)-tmp58_*(tmp41_)))/tmp55_;
  mCompDer[0][3] = ((tmp50_*(tmp45_)-(tmp32_)*(tmp28_))*(tmp43_)-(tmp48_)*(tmp50_*(tmp37_)-tmp60_*(tmp28_)))/tmp55_;
  mCompDer[0][4] = ((tmp54_*(tmp45_)-(tmp52_)*(tmp28_))*(tmp43_)-(tmp48_)*(tmp54_*(tmp37_)-tmp62_*(tmp28_)))/tmp55_;
  mCompDer[0][5] = ((tmp58_*(tmp45_)-(tmp56_)*(tmp28_))*(tmp43_)-(tmp48_)*(tmp58_*(tmp37_)-tmp64_*(tmp28_)))/tmp55_;
  mCompDer[0][6] = (((tmp72_*(tmp45_)+(tmp67_)*(tmp25_))-(tmp74_*(tmp34_)+(tmp70_)*(tmp28_)))*(tmp43_)-(tmp48_)*((-((tmp67_)*tmp29_)*(tmp25_)+tmp72_*(tmp37_))-(tmp74_*(tmp41_)+-((tmp70_)*tmp29_)*(tmp28_))))/tmp55_;
  mCompDer[0][7] = (((tmp82_*(tmp45_)+(tmp77_)*(tmp25_))-(tmp84_*(tmp34_)+(tmp80_)*(tmp28_)))*(tmp43_)-(tmp48_)*((-((tmp77_)*tmp29_)*(tmp25_)+tmp82_*(tmp37_))-(tmp84_*(tmp41_)+-((tmp80_)*tmp29_)*(tmp28_))))/tmp55_;
  mCompDer[0][8] = -((tmp48_)*(tmp25_))/tmp55_;
  mCompDer[0][9] = (-(tmp34_)*(tmp43_)-(tmp48_)*-(tmp41_))/tmp55_;
  mCompDer[0][10] = (tmp85_*(tmp25_)*(tmp43_))/tmp55_;
  mCompDer[0][11] = -((tmp48_)*-(tmp28_))/tmp55_;
  mCompDer[0][12] = ((tmp45_)*(tmp43_)-(tmp48_)*(tmp37_))/tmp55_;
  mCompDer[0][13] = (-(tmp85_*(tmp28_))*(tmp43_))/tmp55_;
  mCompDer[0][14] = -((tmp48_)*(tmp87_*(tmp25_)-tmp86_*(tmp28_)))/tmp55_;
  mCompDer[0][15] = ((tmp86_*(tmp45_)-tmp87_*(tmp34_))*(tmp43_)-(tmp48_)*(tmp86_*(tmp37_)-tmp87_*(tmp41_)))/tmp55_;
}


void cEqHomogrSpaceInitX::ComputeValDerivHessian()
{
  ELISE_ASSERT(false,"Foncteur cEqHomogrSpaceInitX Has no Der Sec");
}

void cEqHomogrSpaceInitX::SetXL1(double aVal){ mLocXL1 = aVal;}
void cEqHomogrSpaceInitX::SetXL2(double aVal){ mLocXL2 = aVal;}
void cEqHomogrSpaceInitX::SetYL1(double aVal){ mLocYL1 = aVal;}



double * cEqHomogrSpaceInitX::AdrVarLocFromString(const std::string & aName)
{
   if (aName == "XL1") return & mLocXL1;
   if (aName == "XL2") return & mLocXL2;
   if (aName == "YL1") return & mLocYL1;
   return 0;
}


cElCompiledFonc::cAutoAddEntry cEqHomogrSpaceInitX::mTheAuto("cEqHomogrSpaceInitX",cEqHomogrSpaceInitX::Alloc);


cElCompiledFonc *  cEqHomogrSpaceInitX::Alloc()
{  return new cEqHomogrSpaceInitX();
}


