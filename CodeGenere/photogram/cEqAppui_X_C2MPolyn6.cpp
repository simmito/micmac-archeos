// File Automatically generated by eLiSe
#include "general/all.h"
#include "private/all.h"
#include "cEqAppui_X_C2MPolyn6.h"


cEqAppui_X_C2MPolyn6::cEqAppui_X_C2MPolyn6():
    cElCompiledFonc(1)
{
   AddIntRef (cIncIntervale("Intr",0,53));
   AddIntRef (cIncIntervale("Orient",53,59));
   Close(false);
}



void cEqAppui_X_C2MPolyn6::ComputeVal()
{
   double tmp0_ = mCompCoord[53];
   double tmp1_ = mCompCoord[54];
   double tmp2_ = cos(tmp1_);
   double tmp3_ = sin(tmp0_);
   double tmp4_ = cos(tmp0_);
   double tmp5_ = sin(tmp1_);
   double tmp6_ = mCompCoord[55];
   double tmp7_ = mCompCoord[56];
   double tmp8_ = mLocXTer-tmp7_;
   double tmp9_ = sin(tmp6_);
   double tmp10_ = -(tmp9_);
   double tmp11_ = -(tmp5_);
   double tmp12_ = cos(tmp6_);
   double tmp13_ = mCompCoord[57];
   double tmp14_ = mLocYTer-tmp13_;
   double tmp15_ = mCompCoord[58];
   double tmp16_ = mLocZTer-tmp15_;
   double tmp17_ = mLocXIm/mLocPolyn6_State_0_0;
   double tmp18_ = mLocYIm/mLocPolyn6_State_0_0;
   double tmp19_ = (tmp17_)*(tmp17_);
   double tmp20_ = (tmp18_)*(tmp18_);
   double tmp21_ = tmp19_*(tmp17_);
   double tmp22_ = (tmp18_)*(tmp17_);
   double tmp23_ = tmp22_*(tmp17_);
   double tmp24_ = tmp20_*(tmp17_);
   double tmp25_ = (tmp18_)*tmp20_;
   double tmp26_ = tmp21_*(tmp17_);
   double tmp27_ = tmp23_*(tmp17_);
   double tmp28_ = tmp24_*(tmp17_);
   double tmp29_ = tmp25_*(tmp17_);
   double tmp30_ = (tmp18_)*tmp25_;
   double tmp31_ = tmp26_*(tmp17_);
   double tmp32_ = tmp27_*(tmp17_);
   double tmp33_ = tmp28_*(tmp17_);
   double tmp34_ = tmp29_*(tmp17_);
   double tmp35_ = tmp30_*(tmp17_);
   double tmp36_ = (tmp18_)*tmp30_;

  mVal[0] = (mCompCoord[1]+mCompCoord[0]*((tmp4_*tmp2_*(tmp8_)+tmp3_*tmp2_*(tmp14_)+tmp5_*(tmp16_))/((-(tmp3_)*tmp10_+tmp4_*tmp11_*tmp12_)*(tmp8_)+(tmp4_*tmp10_+tmp3_*tmp11_*tmp12_)*(tmp14_)+tmp2_*tmp12_*(tmp16_))))-((((1+mCompCoord[3])*(tmp17_)+mCompCoord[4]*(tmp18_))-mCompCoord[5]*2*tmp19_+mCompCoord[6]*(tmp17_)*(tmp18_)+mCompCoord[7]*tmp20_)*mLocPolyn6_State_0_0+(mCompCoord[9]*tmp21_+mCompCoord[10]*tmp23_+mCompCoord[11]*tmp24_+mCompCoord[12]*tmp25_+mCompCoord[17]*tmp26_+mCompCoord[18]*tmp27_+mCompCoord[19]*tmp28_+mCompCoord[20]*tmp29_+mCompCoord[21]*tmp30_+mCompCoord[27]*tmp31_+mCompCoord[28]*tmp32_+mCompCoord[29]*tmp33_+mCompCoord[30]*tmp34_+mCompCoord[31]*tmp35_+mCompCoord[32]*tmp36_+mCompCoord[39]*tmp31_*(tmp17_)+mCompCoord[40]*tmp32_*(tmp17_)+mCompCoord[41]*tmp33_*(tmp17_)+mCompCoord[42]*tmp34_*(tmp17_)+mCompCoord[43]*tmp35_*(tmp17_)+mCompCoord[44]*tmp36_*(tmp17_)+mCompCoord[45]*(tmp18_)*tmp36_)*mLocPolyn6_State_0_0);

}


void cEqAppui_X_C2MPolyn6::ComputeValDeriv()
{
   double tmp0_ = mCompCoord[53];
   double tmp1_ = mCompCoord[54];
   double tmp2_ = cos(tmp1_);
   double tmp3_ = sin(tmp0_);
   double tmp4_ = cos(tmp0_);
   double tmp5_ = sin(tmp1_);
   double tmp6_ = mCompCoord[55];
   double tmp7_ = mCompCoord[56];
   double tmp8_ = mLocXTer-tmp7_;
   double tmp9_ = sin(tmp6_);
   double tmp10_ = -(tmp9_);
   double tmp11_ = -(tmp5_);
   double tmp12_ = cos(tmp6_);
   double tmp13_ = mCompCoord[57];
   double tmp14_ = mLocYTer-tmp13_;
   double tmp15_ = mCompCoord[58];
   double tmp16_ = mLocZTer-tmp15_;
   double tmp17_ = mLocXIm/mLocPolyn6_State_0_0;
   double tmp18_ = mLocYIm/mLocPolyn6_State_0_0;
   double tmp19_ = (tmp17_)*(tmp17_);
   double tmp20_ = (tmp18_)*(tmp18_);
   double tmp21_ = tmp19_*(tmp17_);
   double tmp22_ = (tmp18_)*(tmp17_);
   double tmp23_ = tmp22_*(tmp17_);
   double tmp24_ = tmp20_*(tmp17_);
   double tmp25_ = (tmp18_)*tmp20_;
   double tmp26_ = tmp21_*(tmp17_);
   double tmp27_ = tmp23_*(tmp17_);
   double tmp28_ = tmp24_*(tmp17_);
   double tmp29_ = tmp25_*(tmp17_);
   double tmp30_ = (tmp18_)*tmp25_;
   double tmp31_ = tmp26_*(tmp17_);
   double tmp32_ = tmp27_*(tmp17_);
   double tmp33_ = tmp28_*(tmp17_);
   double tmp34_ = tmp29_*(tmp17_);
   double tmp35_ = tmp30_*(tmp17_);
   double tmp36_ = (tmp18_)*tmp30_;
   double tmp37_ = tmp4_*tmp2_;
   double tmp38_ = tmp37_*(tmp8_);
   double tmp39_ = tmp3_*tmp2_;
   double tmp40_ = tmp39_*(tmp14_);
   double tmp41_ = tmp38_+tmp40_;
   double tmp42_ = tmp5_*(tmp16_);
   double tmp43_ = tmp41_+tmp42_;
   double tmp44_ = -(tmp3_);
   double tmp45_ = tmp44_*tmp10_;
   double tmp46_ = tmp4_*tmp11_;
   double tmp47_ = tmp46_*tmp12_;
   double tmp48_ = tmp45_+tmp47_;
   double tmp49_ = (tmp48_)*(tmp8_);
   double tmp50_ = tmp4_*tmp10_;
   double tmp51_ = tmp3_*tmp11_;
   double tmp52_ = tmp51_*tmp12_;
   double tmp53_ = tmp50_+tmp52_;
   double tmp54_ = (tmp53_)*(tmp14_);
   double tmp55_ = tmp49_+tmp54_;
   double tmp56_ = tmp2_*tmp12_;
   double tmp57_ = tmp56_*(tmp16_);
   double tmp58_ = tmp55_+tmp57_;
   double tmp59_ = (tmp43_)/(tmp58_);
   double tmp60_ = (tmp17_)*(tmp18_);
   double tmp61_ = tmp31_*(tmp17_);
   double tmp62_ = tmp32_*(tmp17_);
   double tmp63_ = tmp33_*(tmp17_);
   double tmp64_ = tmp34_*(tmp17_);
   double tmp65_ = tmp35_*(tmp17_);
   double tmp66_ = tmp36_*(tmp17_);
   double tmp67_ = (tmp18_)*tmp36_;
   double tmp68_ = -(1);
   double tmp69_ = tmp68_*tmp3_;
   double tmp70_ = mCompCoord[0];
   double tmp71_ = tmp68_*tmp5_;
   double tmp72_ = -(tmp2_);
   double tmp73_ = ElSquare(tmp58_);
   double tmp74_ = -(tmp12_);
   double tmp75_ = tmp68_*tmp9_;

  mVal[0] = (mCompCoord[1]+tmp70_*(tmp59_))-((((1+mCompCoord[3])*(tmp17_)+mCompCoord[4]*(tmp18_))-mCompCoord[5]*2*tmp19_+mCompCoord[6]*tmp60_+mCompCoord[7]*tmp20_)*mLocPolyn6_State_0_0+(mCompCoord[9]*tmp21_+mCompCoord[10]*tmp23_+mCompCoord[11]*tmp24_+mCompCoord[12]*tmp25_+mCompCoord[17]*tmp26_+mCompCoord[18]*tmp27_+mCompCoord[19]*tmp28_+mCompCoord[20]*tmp29_+mCompCoord[21]*tmp30_+mCompCoord[27]*tmp31_+mCompCoord[28]*tmp32_+mCompCoord[29]*tmp33_+mCompCoord[30]*tmp34_+mCompCoord[31]*tmp35_+mCompCoord[32]*tmp36_+mCompCoord[39]*tmp61_+mCompCoord[40]*tmp62_+mCompCoord[41]*tmp63_+mCompCoord[42]*tmp64_+mCompCoord[43]*tmp65_+mCompCoord[44]*tmp66_+mCompCoord[45]*tmp67_)*mLocPolyn6_State_0_0);

  mCompDer[0][0] = tmp59_;
  mCompDer[0][1] = 1;
  mCompDer[0][2] = 0;
  mCompDer[0][3] = -((tmp17_)*mLocPolyn6_State_0_0);
  mCompDer[0][4] = -((tmp18_)*mLocPolyn6_State_0_0);
  mCompDer[0][5] = -(-(2*tmp19_)*mLocPolyn6_State_0_0);
  mCompDer[0][6] = -(tmp60_*mLocPolyn6_State_0_0);
  mCompDer[0][7] = -(tmp20_*mLocPolyn6_State_0_0);
  mCompDer[0][8] = 0;
  mCompDer[0][9] = -(tmp21_*mLocPolyn6_State_0_0);
  mCompDer[0][10] = -(tmp23_*mLocPolyn6_State_0_0);
  mCompDer[0][11] = -(tmp24_*mLocPolyn6_State_0_0);
  mCompDer[0][12] = -(tmp25_*mLocPolyn6_State_0_0);
  mCompDer[0][13] = 0;
  mCompDer[0][14] = 0;
  mCompDer[0][15] = 0;
  mCompDer[0][16] = 0;
  mCompDer[0][17] = -(tmp26_*mLocPolyn6_State_0_0);
  mCompDer[0][18] = -(tmp27_*mLocPolyn6_State_0_0);
  mCompDer[0][19] = -(tmp28_*mLocPolyn6_State_0_0);
  mCompDer[0][20] = -(tmp29_*mLocPolyn6_State_0_0);
  mCompDer[0][21] = -(tmp30_*mLocPolyn6_State_0_0);
  mCompDer[0][22] = 0;
  mCompDer[0][23] = 0;
  mCompDer[0][24] = 0;
  mCompDer[0][25] = 0;
  mCompDer[0][26] = 0;
  mCompDer[0][27] = -(tmp31_*mLocPolyn6_State_0_0);
  mCompDer[0][28] = -(tmp32_*mLocPolyn6_State_0_0);
  mCompDer[0][29] = -(tmp33_*mLocPolyn6_State_0_0);
  mCompDer[0][30] = -(tmp34_*mLocPolyn6_State_0_0);
  mCompDer[0][31] = -(tmp35_*mLocPolyn6_State_0_0);
  mCompDer[0][32] = -(tmp36_*mLocPolyn6_State_0_0);
  mCompDer[0][33] = 0;
  mCompDer[0][34] = 0;
  mCompDer[0][35] = 0;
  mCompDer[0][36] = 0;
  mCompDer[0][37] = 0;
  mCompDer[0][38] = 0;
  mCompDer[0][39] = -(tmp61_*mLocPolyn6_State_0_0);
  mCompDer[0][40] = -(tmp62_*mLocPolyn6_State_0_0);
  mCompDer[0][41] = -(tmp63_*mLocPolyn6_State_0_0);
  mCompDer[0][42] = -(tmp64_*mLocPolyn6_State_0_0);
  mCompDer[0][43] = -(tmp65_*mLocPolyn6_State_0_0);
  mCompDer[0][44] = -(tmp66_*mLocPolyn6_State_0_0);
  mCompDer[0][45] = -(tmp67_*mLocPolyn6_State_0_0);
  mCompDer[0][46] = 0;
  mCompDer[0][47] = 0;
  mCompDer[0][48] = 0;
  mCompDer[0][49] = 0;
  mCompDer[0][50] = 0;
  mCompDer[0][51] = 0;
  mCompDer[0][52] = 0;
  mCompDer[0][53] = (((tmp69_*tmp2_*(tmp8_)+tmp37_*(tmp14_))*(tmp58_)-(tmp43_)*((-(tmp4_)*tmp10_+tmp69_*tmp11_*tmp12_)*(tmp8_)+(tmp69_*tmp10_+tmp47_)*(tmp14_)))/tmp73_)*tmp70_;
  mCompDer[0][54] = (((tmp71_*tmp4_*(tmp8_)+tmp71_*tmp3_*(tmp14_)+tmp2_*(tmp16_))*(tmp58_)-(tmp43_)*(tmp72_*tmp4_*tmp12_*(tmp8_)+tmp72_*tmp3_*tmp12_*(tmp14_)+tmp71_*tmp12_*(tmp16_)))/tmp73_)*tmp70_;
  mCompDer[0][55] = (-((tmp43_)*((tmp74_*tmp44_+tmp75_*tmp46_)*(tmp8_)+(tmp74_*tmp4_+tmp75_*tmp51_)*(tmp14_)+tmp75_*tmp2_*(tmp16_)))/tmp73_)*tmp70_;
  mCompDer[0][56] = ((tmp68_*tmp37_*(tmp58_)-(tmp43_)*tmp68_*(tmp48_))/tmp73_)*tmp70_;
  mCompDer[0][57] = ((tmp68_*tmp39_*(tmp58_)-(tmp43_)*tmp68_*(tmp53_))/tmp73_)*tmp70_;
  mCompDer[0][58] = ((tmp71_*(tmp58_)-(tmp43_)*tmp68_*tmp56_)/tmp73_)*tmp70_;
}


void cEqAppui_X_C2MPolyn6::ComputeValDerivHessian()
{
  ELISE_ASSERT(false,"Foncteur cEqAppui_X_C2MPolyn6 Has no Der Sec");
}

void cEqAppui_X_C2MPolyn6::SetPolyn6_State_0_0(double aVal){ mLocPolyn6_State_0_0 = aVal;}
void cEqAppui_X_C2MPolyn6::SetXIm(double aVal){ mLocXIm = aVal;}
void cEqAppui_X_C2MPolyn6::SetXTer(double aVal){ mLocXTer = aVal;}
void cEqAppui_X_C2MPolyn6::SetYIm(double aVal){ mLocYIm = aVal;}
void cEqAppui_X_C2MPolyn6::SetYTer(double aVal){ mLocYTer = aVal;}
void cEqAppui_X_C2MPolyn6::SetZTer(double aVal){ mLocZTer = aVal;}



double * cEqAppui_X_C2MPolyn6::AdrVarLocFromString(const std::string & aName)
{
   if (aName == "Polyn6_State_0_0") return & mLocPolyn6_State_0_0;
   if (aName == "XIm") return & mLocXIm;
   if (aName == "XTer") return & mLocXTer;
   if (aName == "YIm") return & mLocYIm;
   if (aName == "YTer") return & mLocYTer;
   if (aName == "ZTer") return & mLocZTer;
   return 0;
}


cElCompiledFonc::cAutoAddEntry cEqAppui_X_C2MPolyn6::mTheAuto("cEqAppui_X_C2MPolyn6",cEqAppui_X_C2MPolyn6::Alloc);


cElCompiledFonc *  cEqAppui_X_C2MPolyn6::Alloc()
{  return new cEqAppui_X_C2MPolyn6();
}


