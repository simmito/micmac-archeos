// File Automatically generated by eLiSe

#include "general/all.h"
#include "private/all.h"
#include "cEqCoplanDCBrownId.h"


cEqCoplanDCBrownId::cEqCoplanDCBrownId():
    cElCompiledFonc(1)
{
   AddIntRef (cIncIntervale("Intr1",0,17));
   AddIntRef (cIncIntervale("Or1",17,23));
   AddIntRef (cIncIntervale("Or2",23,29));
   Close(false);
}



void cEqCoplanDCBrownId::ComputeVal()
{
   double tmp0_ = mLocYL1*mLocYL1;
   double tmp1_ = mLocXL1*mLocXL1;
   double tmp2_ = tmp1_*tmp0_;
   double tmp3_ = mCompCoord[17];
   double tmp4_ = sin(tmp3_);
   double tmp5_ = mCompCoord[18];
   double tmp6_ = mCompCoord[19];
   double tmp7_ = mLocXL1*mLocYL1;
   double tmp8_ = tmp1_*mLocYL1;
   double tmp9_ = mLocXL1*tmp0_;
   double tmp10_ = mCompCoord[15];
   double tmp11_ = mCompCoord[16];
   double tmp12_ = tmp1_+tmp0_;
   double tmp13_ = mCompCoord[0];
   double tmp14_ = cos(tmp3_);
   double tmp15_ = sin(tmp6_);
   double tmp16_ = sin(tmp5_);
   double tmp17_ = -(tmp16_);
   double tmp18_ = tmp4_*tmp17_;
   double tmp19_ = cos(tmp6_);
   double tmp20_ = mCompCoord[3];
   double tmp21_ = 1+tmp20_;
   double tmp22_ = mCompCoord[4];
   double tmp23_ = mCompCoord[5];
   double tmp24_ = mCompCoord[6];
   double tmp25_ = mCompCoord[7];
   double tmp26_ = mCompCoord[8];
   double tmp27_ = mLocYL2*mLocYL2;
   double tmp28_ = mCompCoord[9];
   double tmp29_ = mLocXL2*mLocXL2;
   double tmp30_ = tmp29_*tmp27_;
   double tmp31_ = mCompCoord[1];
   double tmp32_ = mCompCoord[24];
   double tmp33_ = mCompCoord[10];
   double tmp34_ = mLocXL2*mLocYL2;
   double tmp35_ = mCompCoord[11];
   double tmp36_ = mCompCoord[12];
   double tmp37_ = tmp29_*mLocYL2;
   double tmp38_ = mCompCoord[13];
   double tmp39_ = mLocXL2*tmp27_;
   double tmp40_ = mCompCoord[14];
   double tmp41_ = tmp29_+tmp27_;
   double tmp42_ = mCompCoord[2];
   double tmp43_ = cos(tmp32_);
   double tmp44_ = mCompCoord[25];
   double tmp45_ = (tmp21_)*mLocXL1;
   double tmp46_ = tmp22_*mLocYL1;
   double tmp47_ = tmp45_+tmp46_;
   double tmp48_ = tmp23_*tmp7_;
   double tmp49_ = tmp47_+tmp48_;
   double tmp50_ = tmp24_*tmp0_;
   double tmp51_ = tmp49_+tmp50_;
   double tmp52_ = tmp25_*tmp8_;
   double tmp53_ = tmp51_+tmp52_;
   double tmp54_ = tmp26_*tmp9_;
   double tmp55_ = tmp53_+tmp54_;
   double tmp56_ = tmp28_*tmp2_;
   double tmp57_ = tmp55_+tmp56_;
   double tmp58_ = mLocXL1/mLocDCBrown_State_0_0;
   double tmp59_ = tmp10_*(tmp58_);
   double tmp60_ = tmp59_*tmp2_;
   double tmp61_ = tmp57_+tmp60_;
   double tmp62_ = tmp11_*mLocXL1;
   double tmp63_ = tmp62_*(tmp12_);
   double tmp64_ = tmp61_+tmp63_;
   double tmp65_ = (tmp64_)-tmp31_;
   double tmp66_ = (tmp65_)/tmp13_;
   double tmp67_ = cos(tmp5_);
   double tmp68_ = tmp33_*tmp7_;
   double tmp69_ = mLocYL1+tmp68_;
   double tmp70_ = tmp35_*tmp1_;
   double tmp71_ = tmp69_+tmp70_;
   double tmp72_ = tmp36_*tmp8_;
   double tmp73_ = tmp71_+tmp72_;
   double tmp74_ = tmp38_*tmp9_;
   double tmp75_ = tmp73_+tmp74_;
   double tmp76_ = tmp40_*tmp2_;
   double tmp77_ = tmp75_+tmp76_;
   double tmp78_ = mLocYL1/mLocDCBrown_State_0_0;
   double tmp79_ = tmp10_*(tmp78_);
   double tmp80_ = tmp79_*tmp2_;
   double tmp81_ = tmp77_+tmp80_;
   double tmp82_ = tmp11_*mLocYL1;
   double tmp83_ = tmp82_*(tmp12_);
   double tmp84_ = tmp81_+tmp83_;
   double tmp85_ = (tmp84_)-tmp42_;
   double tmp86_ = (tmp85_)/tmp13_;
   double tmp87_ = (tmp21_)*mLocXL2;
   double tmp88_ = tmp22_*mLocYL2;
   double tmp89_ = tmp87_+tmp88_;
   double tmp90_ = tmp23_*tmp34_;
   double tmp91_ = tmp89_+tmp90_;
   double tmp92_ = tmp24_*tmp27_;
   double tmp93_ = tmp91_+tmp92_;
   double tmp94_ = tmp25_*tmp37_;
   double tmp95_ = tmp93_+tmp94_;
   double tmp96_ = tmp26_*tmp39_;
   double tmp97_ = tmp95_+tmp96_;
   double tmp98_ = tmp28_*tmp30_;
   double tmp99_ = tmp97_+tmp98_;
   double tmp100_ = mLocXL2/mLocDCBrown_State_0_1;
   double tmp101_ = tmp10_*(tmp100_);
   double tmp102_ = tmp101_*tmp30_;
   double tmp103_ = tmp99_+tmp102_;
   double tmp104_ = tmp11_*mLocXL2;
   double tmp105_ = tmp104_*(tmp41_);
   double tmp106_ = tmp103_+tmp105_;
   double tmp107_ = (tmp106_)-tmp31_;
   double tmp108_ = (tmp107_)/tmp13_;
   double tmp109_ = mCompCoord[23];
   double tmp110_ = cos(tmp44_);
   double tmp111_ = sin(tmp109_);
   double tmp112_ = sin(tmp32_);
   double tmp113_ = sin(tmp44_);
   double tmp114_ = tmp33_*tmp34_;
   double tmp115_ = mLocYL2+tmp114_;
   double tmp116_ = tmp35_*tmp29_;
   double tmp117_ = tmp115_+tmp116_;
   double tmp118_ = tmp36_*tmp37_;
   double tmp119_ = tmp117_+tmp118_;
   double tmp120_ = tmp38_*tmp39_;
   double tmp121_ = tmp119_+tmp120_;
   double tmp122_ = tmp40_*tmp30_;
   double tmp123_ = tmp121_+tmp122_;
   double tmp124_ = mLocYL2/mLocDCBrown_State_0_1;
   double tmp125_ = tmp10_*(tmp124_);
   double tmp126_ = tmp125_*tmp30_;
   double tmp127_ = tmp123_+tmp126_;
   double tmp128_ = tmp11_*mLocYL2;
   double tmp129_ = tmp128_*(tmp41_);
   double tmp130_ = tmp127_+tmp129_;
   double tmp131_ = (tmp130_)-tmp42_;
   double tmp132_ = (tmp131_)/tmp13_;
   double tmp133_ = cos(tmp109_);
   double tmp134_ = -(tmp112_);
   double tmp135_ = tmp111_*tmp134_;
   double tmp136_ = tmp16_*(tmp66_);
   double tmp137_ = tmp67_*tmp15_;
   double tmp138_ = tmp137_*(tmp86_);
   double tmp139_ = tmp136_+tmp138_;
   double tmp140_ = tmp67_*tmp19_;
   double tmp141_ = tmp139_+tmp140_;
   double tmp142_ = -(tmp111_);
   double tmp143_ = -(tmp113_);
   double tmp144_ = tmp133_*tmp134_;
   double tmp145_ = -(tmp4_);
   double tmp146_ = -(tmp15_);
   double tmp147_ = tmp14_*tmp17_;
   double tmp148_ = tmp112_*(tmp108_);
   double tmp149_ = tmp43_*tmp113_;
   double tmp150_ = tmp149_*(tmp132_);
   double tmp151_ = tmp148_+tmp150_;
   double tmp152_ = tmp43_*tmp110_;
   double tmp153_ = tmp151_+tmp152_;
   double tmp154_ = tmp14_*tmp67_;
   double tmp155_ = tmp154_*(tmp66_);
   double tmp156_ = tmp145_*tmp19_;
   double tmp157_ = tmp147_*tmp15_;
   double tmp158_ = tmp156_+tmp157_;
   double tmp159_ = (tmp158_)*(tmp86_);
   double tmp160_ = tmp155_+tmp159_;
   double tmp161_ = tmp145_*tmp146_;
   double tmp162_ = tmp147_*tmp19_;
   double tmp163_ = tmp161_+tmp162_;
   double tmp164_ = tmp160_+tmp163_;
   double tmp165_ = tmp111_*tmp43_;
   double tmp166_ = tmp165_*(tmp108_);
   double tmp167_ = tmp133_*tmp110_;
   double tmp168_ = tmp135_*tmp113_;
   double tmp169_ = tmp167_+tmp168_;
   double tmp170_ = (tmp169_)*(tmp132_);
   double tmp171_ = tmp166_+tmp170_;
   double tmp172_ = tmp133_*tmp143_;
   double tmp173_ = tmp135_*tmp110_;
   double tmp174_ = tmp172_+tmp173_;
   double tmp175_ = tmp171_+tmp174_;
   double tmp176_ = tmp4_*tmp67_;
   double tmp177_ = tmp176_*(tmp66_);
   double tmp178_ = tmp14_*tmp19_;
   double tmp179_ = tmp18_*tmp15_;
   double tmp180_ = tmp178_+tmp179_;
   double tmp181_ = (tmp180_)*(tmp86_);
   double tmp182_ = tmp177_+tmp181_;
   double tmp183_ = tmp14_*tmp146_;
   double tmp184_ = tmp18_*tmp19_;
   double tmp185_ = tmp183_+tmp184_;
   double tmp186_ = tmp182_+tmp185_;
   double tmp187_ = tmp133_*tmp43_;
   double tmp188_ = tmp187_*(tmp108_);
   double tmp189_ = tmp142_*tmp110_;
   double tmp190_ = tmp144_*tmp113_;
   double tmp191_ = tmp189_+tmp190_;
   double tmp192_ = (tmp191_)*(tmp132_);
   double tmp193_ = tmp188_+tmp192_;
   double tmp194_ = tmp142_*tmp143_;
   double tmp195_ = tmp144_*tmp110_;
   double tmp196_ = tmp194_+tmp195_;
   double tmp197_ = tmp193_+tmp196_;
   double tmp198_ = mCompCoord[26];
   double tmp199_ = mCompCoord[20];
   double tmp200_ = tmp198_-tmp199_;
   double tmp201_ = mCompCoord[27];
   double tmp202_ = mCompCoord[21];
   double tmp203_ = tmp201_-tmp202_;
   double tmp204_ = mCompCoord[28];
   double tmp205_ = mCompCoord[22];
   double tmp206_ = tmp204_-tmp205_;

  mVal[0] = (((tmp186_)*(tmp153_)-(tmp141_)*(tmp175_))*(tmp200_)+((tmp141_)*(tmp197_)-(tmp164_)*(tmp153_))*(tmp203_)+((tmp164_)*(tmp175_)-(tmp186_)*(tmp197_))*(tmp206_))/sqrt((tmp200_)*(tmp200_)+(tmp203_)*(tmp203_)+(tmp206_)*(tmp206_));

}


void cEqCoplanDCBrownId::ComputeValDeriv()
{
   double tmp0_ = mLocYL1*mLocYL1;
   double tmp1_ = mLocXL1*mLocXL1;
   double tmp2_ = tmp1_*tmp0_;
   double tmp3_ = mCompCoord[17];
   double tmp4_ = sin(tmp3_);
   double tmp5_ = mCompCoord[18];
   double tmp6_ = mCompCoord[19];
   double tmp7_ = mLocXL1*mLocYL1;
   double tmp8_ = tmp1_*mLocYL1;
   double tmp9_ = mLocXL1*tmp0_;
   double tmp10_ = mCompCoord[15];
   double tmp11_ = mCompCoord[16];
   double tmp12_ = tmp1_+tmp0_;
   double tmp13_ = mCompCoord[0];
   double tmp14_ = cos(tmp3_);
   double tmp15_ = sin(tmp6_);
   double tmp16_ = sin(tmp5_);
   double tmp17_ = -(tmp16_);
   double tmp18_ = tmp4_*tmp17_;
   double tmp19_ = cos(tmp6_);
   double tmp20_ = mCompCoord[3];
   double tmp21_ = 1+tmp20_;
   double tmp22_ = mCompCoord[4];
   double tmp23_ = mCompCoord[5];
   double tmp24_ = mCompCoord[6];
   double tmp25_ = mCompCoord[7];
   double tmp26_ = mCompCoord[8];
   double tmp27_ = mLocYL2*mLocYL2;
   double tmp28_ = mCompCoord[9];
   double tmp29_ = mLocXL2*mLocXL2;
   double tmp30_ = tmp29_*tmp27_;
   double tmp31_ = mCompCoord[1];
   double tmp32_ = mCompCoord[24];
   double tmp33_ = mCompCoord[10];
   double tmp34_ = mLocXL2*mLocYL2;
   double tmp35_ = mCompCoord[11];
   double tmp36_ = mCompCoord[12];
   double tmp37_ = tmp29_*mLocYL2;
   double tmp38_ = mCompCoord[13];
   double tmp39_ = mLocXL2*tmp27_;
   double tmp40_ = mCompCoord[14];
   double tmp41_ = tmp29_+tmp27_;
   double tmp42_ = mCompCoord[2];
   double tmp43_ = cos(tmp32_);
   double tmp44_ = mCompCoord[25];
   double tmp45_ = (tmp21_)*mLocXL1;
   double tmp46_ = tmp22_*mLocYL1;
   double tmp47_ = tmp45_+tmp46_;
   double tmp48_ = tmp23_*tmp7_;
   double tmp49_ = tmp47_+tmp48_;
   double tmp50_ = tmp24_*tmp0_;
   double tmp51_ = tmp49_+tmp50_;
   double tmp52_ = tmp25_*tmp8_;
   double tmp53_ = tmp51_+tmp52_;
   double tmp54_ = tmp26_*tmp9_;
   double tmp55_ = tmp53_+tmp54_;
   double tmp56_ = tmp28_*tmp2_;
   double tmp57_ = tmp55_+tmp56_;
   double tmp58_ = mLocXL1/mLocDCBrown_State_0_0;
   double tmp59_ = tmp10_*(tmp58_);
   double tmp60_ = tmp59_*tmp2_;
   double tmp61_ = tmp57_+tmp60_;
   double tmp62_ = tmp11_*mLocXL1;
   double tmp63_ = tmp62_*(tmp12_);
   double tmp64_ = tmp61_+tmp63_;
   double tmp65_ = (tmp64_)-tmp31_;
   double tmp66_ = (tmp65_)/tmp13_;
   double tmp67_ = cos(tmp5_);
   double tmp68_ = tmp33_*tmp7_;
   double tmp69_ = mLocYL1+tmp68_;
   double tmp70_ = tmp35_*tmp1_;
   double tmp71_ = tmp69_+tmp70_;
   double tmp72_ = tmp36_*tmp8_;
   double tmp73_ = tmp71_+tmp72_;
   double tmp74_ = tmp38_*tmp9_;
   double tmp75_ = tmp73_+tmp74_;
   double tmp76_ = tmp40_*tmp2_;
   double tmp77_ = tmp75_+tmp76_;
   double tmp78_ = mLocYL1/mLocDCBrown_State_0_0;
   double tmp79_ = tmp10_*(tmp78_);
   double tmp80_ = tmp79_*tmp2_;
   double tmp81_ = tmp77_+tmp80_;
   double tmp82_ = tmp11_*mLocYL1;
   double tmp83_ = tmp82_*(tmp12_);
   double tmp84_ = tmp81_+tmp83_;
   double tmp85_ = (tmp84_)-tmp42_;
   double tmp86_ = (tmp85_)/tmp13_;
   double tmp87_ = (tmp21_)*mLocXL2;
   double tmp88_ = tmp22_*mLocYL2;
   double tmp89_ = tmp87_+tmp88_;
   double tmp90_ = tmp23_*tmp34_;
   double tmp91_ = tmp89_+tmp90_;
   double tmp92_ = tmp24_*tmp27_;
   double tmp93_ = tmp91_+tmp92_;
   double tmp94_ = tmp25_*tmp37_;
   double tmp95_ = tmp93_+tmp94_;
   double tmp96_ = tmp26_*tmp39_;
   double tmp97_ = tmp95_+tmp96_;
   double tmp98_ = tmp28_*tmp30_;
   double tmp99_ = tmp97_+tmp98_;
   double tmp100_ = mLocXL2/mLocDCBrown_State_0_1;
   double tmp101_ = tmp10_*(tmp100_);
   double tmp102_ = tmp101_*tmp30_;
   double tmp103_ = tmp99_+tmp102_;
   double tmp104_ = tmp11_*mLocXL2;
   double tmp105_ = tmp104_*(tmp41_);
   double tmp106_ = tmp103_+tmp105_;
   double tmp107_ = (tmp106_)-tmp31_;
   double tmp108_ = (tmp107_)/tmp13_;
   double tmp109_ = mCompCoord[23];
   double tmp110_ = cos(tmp44_);
   double tmp111_ = sin(tmp109_);
   double tmp112_ = sin(tmp32_);
   double tmp113_ = sin(tmp44_);
   double tmp114_ = tmp33_*tmp34_;
   double tmp115_ = mLocYL2+tmp114_;
   double tmp116_ = tmp35_*tmp29_;
   double tmp117_ = tmp115_+tmp116_;
   double tmp118_ = tmp36_*tmp37_;
   double tmp119_ = tmp117_+tmp118_;
   double tmp120_ = tmp38_*tmp39_;
   double tmp121_ = tmp119_+tmp120_;
   double tmp122_ = tmp40_*tmp30_;
   double tmp123_ = tmp121_+tmp122_;
   double tmp124_ = mLocYL2/mLocDCBrown_State_0_1;
   double tmp125_ = tmp10_*(tmp124_);
   double tmp126_ = tmp125_*tmp30_;
   double tmp127_ = tmp123_+tmp126_;
   double tmp128_ = tmp11_*mLocYL2;
   double tmp129_ = tmp128_*(tmp41_);
   double tmp130_ = tmp127_+tmp129_;
   double tmp131_ = (tmp130_)-tmp42_;
   double tmp132_ = (tmp131_)/tmp13_;
   double tmp133_ = cos(tmp109_);
   double tmp134_ = -(tmp112_);
   double tmp135_ = tmp111_*tmp134_;
   double tmp136_ = tmp16_*(tmp66_);
   double tmp137_ = tmp67_*tmp15_;
   double tmp138_ = tmp137_*(tmp86_);
   double tmp139_ = tmp136_+tmp138_;
   double tmp140_ = tmp67_*tmp19_;
   double tmp141_ = tmp139_+tmp140_;
   double tmp142_ = -(tmp111_);
   double tmp143_ = -(tmp113_);
   double tmp144_ = tmp133_*tmp134_;
   double tmp145_ = -(tmp4_);
   double tmp146_ = -(tmp15_);
   double tmp147_ = tmp14_*tmp17_;
   double tmp148_ = tmp112_*(tmp108_);
   double tmp149_ = tmp43_*tmp113_;
   double tmp150_ = tmp149_*(tmp132_);
   double tmp151_ = tmp148_+tmp150_;
   double tmp152_ = tmp43_*tmp110_;
   double tmp153_ = tmp151_+tmp152_;
   double tmp154_ = tmp14_*tmp67_;
   double tmp155_ = tmp154_*(tmp66_);
   double tmp156_ = tmp145_*tmp19_;
   double tmp157_ = tmp147_*tmp15_;
   double tmp158_ = tmp156_+tmp157_;
   double tmp159_ = (tmp158_)*(tmp86_);
   double tmp160_ = tmp155_+tmp159_;
   double tmp161_ = tmp145_*tmp146_;
   double tmp162_ = tmp147_*tmp19_;
   double tmp163_ = tmp161_+tmp162_;
   double tmp164_ = tmp160_+tmp163_;
   double tmp165_ = tmp111_*tmp43_;
   double tmp166_ = tmp165_*(tmp108_);
   double tmp167_ = tmp133_*tmp110_;
   double tmp168_ = tmp135_*tmp113_;
   double tmp169_ = tmp167_+tmp168_;
   double tmp170_ = (tmp169_)*(tmp132_);
   double tmp171_ = tmp166_+tmp170_;
   double tmp172_ = tmp133_*tmp143_;
   double tmp173_ = tmp135_*tmp110_;
   double tmp174_ = tmp172_+tmp173_;
   double tmp175_ = tmp171_+tmp174_;
   double tmp176_ = tmp4_*tmp67_;
   double tmp177_ = tmp176_*(tmp66_);
   double tmp178_ = tmp14_*tmp19_;
   double tmp179_ = tmp18_*tmp15_;
   double tmp180_ = tmp178_+tmp179_;
   double tmp181_ = (tmp180_)*(tmp86_);
   double tmp182_ = tmp177_+tmp181_;
   double tmp183_ = tmp14_*tmp146_;
   double tmp184_ = tmp18_*tmp19_;
   double tmp185_ = tmp183_+tmp184_;
   double tmp186_ = tmp182_+tmp185_;
   double tmp187_ = tmp133_*tmp43_;
   double tmp188_ = tmp187_*(tmp108_);
   double tmp189_ = tmp142_*tmp110_;
   double tmp190_ = tmp144_*tmp113_;
   double tmp191_ = tmp189_+tmp190_;
   double tmp192_ = (tmp191_)*(tmp132_);
   double tmp193_ = tmp188_+tmp192_;
   double tmp194_ = tmp142_*tmp143_;
   double tmp195_ = tmp144_*tmp110_;
   double tmp196_ = tmp194_+tmp195_;
   double tmp197_ = tmp193_+tmp196_;
   double tmp198_ = mCompCoord[26];
   double tmp199_ = mCompCoord[20];
   double tmp200_ = tmp198_-tmp199_;
   double tmp201_ = mCompCoord[27];
   double tmp202_ = mCompCoord[21];
   double tmp203_ = tmp201_-tmp202_;
   double tmp204_ = mCompCoord[28];
   double tmp205_ = mCompCoord[22];
   double tmp206_ = tmp204_-tmp205_;
   double tmp207_ = ElSquare(tmp13_);
   double tmp208_ = -(tmp65_);
   double tmp209_ = tmp208_/tmp207_;
   double tmp210_ = -(tmp85_);
   double tmp211_ = tmp210_/tmp207_;
   double tmp212_ = -(tmp107_);
   double tmp213_ = tmp212_/tmp207_;
   double tmp214_ = -(tmp131_);
   double tmp215_ = tmp214_/tmp207_;
   double tmp216_ = (tmp209_)*tmp16_;
   double tmp217_ = (tmp211_)*tmp137_;
   double tmp218_ = tmp216_+tmp217_;
   double tmp219_ = (tmp213_)*tmp112_;
   double tmp220_ = (tmp215_)*tmp149_;
   double tmp221_ = tmp219_+tmp220_;
   double tmp222_ = (tmp209_)*tmp154_;
   double tmp223_ = (tmp211_)*(tmp158_);
   double tmp224_ = tmp222_+tmp223_;
   double tmp225_ = (tmp213_)*tmp165_;
   double tmp226_ = (tmp215_)*(tmp169_);
   double tmp227_ = tmp225_+tmp226_;
   double tmp228_ = (tmp209_)*tmp176_;
   double tmp229_ = (tmp211_)*(tmp180_);
   double tmp230_ = tmp228_+tmp229_;
   double tmp231_ = (tmp213_)*tmp187_;
   double tmp232_ = (tmp215_)*(tmp191_);
   double tmp233_ = tmp231_+tmp232_;
   double tmp234_ = (tmp200_)*(tmp200_);
   double tmp235_ = (tmp203_)*(tmp203_);
   double tmp236_ = tmp234_+tmp235_;
   double tmp237_ = (tmp206_)*(tmp206_);
   double tmp238_ = tmp236_+tmp237_;
   double tmp239_ = sqrt(tmp238_);
   double tmp240_ = -(1);
   double tmp241_ = tmp240_*tmp13_;
   double tmp242_ = (tmp241_)/tmp207_;
   double tmp243_ = (tmp242_)*tmp16_;
   double tmp244_ = (tmp242_)*tmp112_;
   double tmp245_ = (tmp242_)*tmp154_;
   double tmp246_ = (tmp242_)*tmp165_;
   double tmp247_ = (tmp242_)*tmp176_;
   double tmp248_ = (tmp242_)*tmp187_;
   double tmp249_ = ElSquare(tmp239_);
   double tmp250_ = (tmp242_)*tmp137_;
   double tmp251_ = (tmp242_)*tmp149_;
   double tmp252_ = (tmp242_)*(tmp158_);
   double tmp253_ = (tmp242_)*(tmp169_);
   double tmp254_ = (tmp242_)*(tmp180_);
   double tmp255_ = (tmp242_)*(tmp191_);
   double tmp256_ = mLocXL1*tmp13_;
   double tmp257_ = (tmp256_)/tmp207_;
   double tmp258_ = mLocXL2*tmp13_;
   double tmp259_ = (tmp258_)/tmp207_;
   double tmp260_ = (tmp257_)*tmp16_;
   double tmp261_ = (tmp259_)*tmp112_;
   double tmp262_ = (tmp257_)*tmp154_;
   double tmp263_ = (tmp259_)*tmp165_;
   double tmp264_ = (tmp257_)*tmp176_;
   double tmp265_ = (tmp259_)*tmp187_;
   double tmp266_ = mLocYL1*tmp13_;
   double tmp267_ = (tmp266_)/tmp207_;
   double tmp268_ = mLocYL2*tmp13_;
   double tmp269_ = (tmp268_)/tmp207_;
   double tmp270_ = (tmp267_)*tmp16_;
   double tmp271_ = (tmp269_)*tmp112_;
   double tmp272_ = (tmp267_)*tmp154_;
   double tmp273_ = (tmp269_)*tmp165_;
   double tmp274_ = (tmp267_)*tmp176_;
   double tmp275_ = (tmp269_)*tmp187_;
   double tmp276_ = tmp7_*tmp13_;
   double tmp277_ = (tmp276_)/tmp207_;
   double tmp278_ = tmp34_*tmp13_;
   double tmp279_ = (tmp278_)/tmp207_;
   double tmp280_ = (tmp277_)*tmp16_;
   double tmp281_ = (tmp279_)*tmp112_;
   double tmp282_ = (tmp277_)*tmp154_;
   double tmp283_ = (tmp279_)*tmp165_;
   double tmp284_ = (tmp277_)*tmp176_;
   double tmp285_ = (tmp279_)*tmp187_;
   double tmp286_ = tmp0_*tmp13_;
   double tmp287_ = (tmp286_)/tmp207_;
   double tmp288_ = tmp27_*tmp13_;
   double tmp289_ = (tmp288_)/tmp207_;
   double tmp290_ = (tmp287_)*tmp16_;
   double tmp291_ = (tmp289_)*tmp112_;
   double tmp292_ = (tmp287_)*tmp154_;
   double tmp293_ = (tmp289_)*tmp165_;
   double tmp294_ = (tmp287_)*tmp176_;
   double tmp295_ = (tmp289_)*tmp187_;
   double tmp296_ = tmp8_*tmp13_;
   double tmp297_ = (tmp296_)/tmp207_;
   double tmp298_ = tmp37_*tmp13_;
   double tmp299_ = (tmp298_)/tmp207_;
   double tmp300_ = (tmp297_)*tmp16_;
   double tmp301_ = (tmp299_)*tmp112_;
   double tmp302_ = (tmp297_)*tmp154_;
   double tmp303_ = (tmp299_)*tmp165_;
   double tmp304_ = (tmp297_)*tmp176_;
   double tmp305_ = (tmp299_)*tmp187_;
   double tmp306_ = tmp9_*tmp13_;
   double tmp307_ = (tmp306_)/tmp207_;
   double tmp308_ = tmp39_*tmp13_;
   double tmp309_ = (tmp308_)/tmp207_;
   double tmp310_ = (tmp307_)*tmp16_;
   double tmp311_ = (tmp309_)*tmp112_;
   double tmp312_ = (tmp307_)*tmp154_;
   double tmp313_ = (tmp309_)*tmp165_;
   double tmp314_ = (tmp307_)*tmp176_;
   double tmp315_ = (tmp309_)*tmp187_;
   double tmp316_ = tmp2_*tmp13_;
   double tmp317_ = (tmp316_)/tmp207_;
   double tmp318_ = tmp30_*tmp13_;
   double tmp319_ = (tmp318_)/tmp207_;
   double tmp320_ = (tmp317_)*tmp16_;
   double tmp321_ = (tmp319_)*tmp112_;
   double tmp322_ = (tmp317_)*tmp154_;
   double tmp323_ = (tmp319_)*tmp165_;
   double tmp324_ = (tmp317_)*tmp176_;
   double tmp325_ = (tmp319_)*tmp187_;
   double tmp326_ = (tmp277_)*tmp137_;
   double tmp327_ = (tmp279_)*tmp149_;
   double tmp328_ = (tmp277_)*(tmp158_);
   double tmp329_ = (tmp279_)*(tmp169_);
   double tmp330_ = (tmp277_)*(tmp180_);
   double tmp331_ = (tmp279_)*(tmp191_);
   double tmp332_ = tmp1_*tmp13_;
   double tmp333_ = (tmp332_)/tmp207_;
   double tmp334_ = tmp29_*tmp13_;
   double tmp335_ = (tmp334_)/tmp207_;
   double tmp336_ = (tmp333_)*tmp137_;
   double tmp337_ = (tmp335_)*tmp149_;
   double tmp338_ = (tmp333_)*(tmp158_);
   double tmp339_ = (tmp335_)*(tmp169_);
   double tmp340_ = (tmp333_)*(tmp180_);
   double tmp341_ = (tmp335_)*(tmp191_);
   double tmp342_ = (tmp297_)*tmp137_;
   double tmp343_ = (tmp299_)*tmp149_;
   double tmp344_ = (tmp297_)*(tmp158_);
   double tmp345_ = (tmp299_)*(tmp169_);
   double tmp346_ = (tmp297_)*(tmp180_);
   double tmp347_ = (tmp299_)*(tmp191_);
   double tmp348_ = (tmp307_)*tmp137_;
   double tmp349_ = (tmp309_)*tmp149_;
   double tmp350_ = (tmp307_)*(tmp158_);
   double tmp351_ = (tmp309_)*(tmp169_);
   double tmp352_ = (tmp307_)*(tmp180_);
   double tmp353_ = (tmp309_)*(tmp191_);
   double tmp354_ = (tmp317_)*tmp137_;
   double tmp355_ = (tmp319_)*tmp149_;
   double tmp356_ = (tmp317_)*(tmp158_);
   double tmp357_ = (tmp319_)*(tmp169_);
   double tmp358_ = (tmp317_)*(tmp180_);
   double tmp359_ = (tmp319_)*(tmp191_);
   double tmp360_ = (tmp58_)*tmp2_;
   double tmp361_ = tmp360_*tmp13_;
   double tmp362_ = (tmp361_)/tmp207_;
   double tmp363_ = (tmp78_)*tmp2_;
   double tmp364_ = tmp363_*tmp13_;
   double tmp365_ = (tmp364_)/tmp207_;
   double tmp366_ = (tmp100_)*tmp30_;
   double tmp367_ = tmp366_*tmp13_;
   double tmp368_ = (tmp367_)/tmp207_;
   double tmp369_ = (tmp124_)*tmp30_;
   double tmp370_ = tmp369_*tmp13_;
   double tmp371_ = (tmp370_)/tmp207_;
   double tmp372_ = (tmp362_)*tmp16_;
   double tmp373_ = (tmp365_)*tmp137_;
   double tmp374_ = tmp372_+tmp373_;
   double tmp375_ = (tmp368_)*tmp112_;
   double tmp376_ = (tmp371_)*tmp149_;
   double tmp377_ = tmp375_+tmp376_;
   double tmp378_ = (tmp362_)*tmp154_;
   double tmp379_ = (tmp365_)*(tmp158_);
   double tmp380_ = tmp378_+tmp379_;
   double tmp381_ = (tmp368_)*tmp165_;
   double tmp382_ = (tmp371_)*(tmp169_);
   double tmp383_ = tmp381_+tmp382_;
   double tmp384_ = (tmp362_)*tmp176_;
   double tmp385_ = (tmp365_)*(tmp180_);
   double tmp386_ = tmp384_+tmp385_;
   double tmp387_ = (tmp368_)*tmp187_;
   double tmp388_ = (tmp371_)*(tmp191_);
   double tmp389_ = tmp387_+tmp388_;
   double tmp390_ = mLocXL1*(tmp12_);
   double tmp391_ = tmp390_*tmp13_;
   double tmp392_ = (tmp391_)/tmp207_;
   double tmp393_ = mLocYL1*(tmp12_);
   double tmp394_ = tmp393_*tmp13_;
   double tmp395_ = (tmp394_)/tmp207_;
   double tmp396_ = mLocXL2*(tmp41_);
   double tmp397_ = tmp396_*tmp13_;
   double tmp398_ = (tmp397_)/tmp207_;
   double tmp399_ = mLocYL2*(tmp41_);
   double tmp400_ = tmp399_*tmp13_;
   double tmp401_ = (tmp400_)/tmp207_;
   double tmp402_ = (tmp392_)*tmp16_;
   double tmp403_ = (tmp395_)*tmp137_;
   double tmp404_ = tmp402_+tmp403_;
   double tmp405_ = (tmp398_)*tmp112_;
   double tmp406_ = (tmp401_)*tmp149_;
   double tmp407_ = tmp405_+tmp406_;
   double tmp408_ = (tmp392_)*tmp154_;
   double tmp409_ = (tmp395_)*(tmp158_);
   double tmp410_ = tmp408_+tmp409_;
   double tmp411_ = (tmp398_)*tmp165_;
   double tmp412_ = (tmp401_)*(tmp169_);
   double tmp413_ = tmp411_+tmp412_;
   double tmp414_ = (tmp392_)*tmp176_;
   double tmp415_ = (tmp395_)*(tmp180_);
   double tmp416_ = tmp414_+tmp415_;
   double tmp417_ = (tmp398_)*tmp187_;
   double tmp418_ = (tmp401_)*(tmp191_);
   double tmp419_ = tmp417_+tmp418_;
   double tmp420_ = tmp240_*tmp4_;
   double tmp421_ = -(tmp14_);
   double tmp422_ = tmp420_*tmp17_;
   double tmp423_ = tmp420_*tmp67_;
   double tmp424_ = tmp423_*(tmp66_);
   double tmp425_ = tmp421_*tmp19_;
   double tmp426_ = tmp422_*tmp15_;
   double tmp427_ = tmp425_+tmp426_;
   double tmp428_ = (tmp427_)*(tmp86_);
   double tmp429_ = tmp424_+tmp428_;
   double tmp430_ = tmp421_*tmp146_;
   double tmp431_ = tmp422_*tmp19_;
   double tmp432_ = tmp430_+tmp431_;
   double tmp433_ = tmp429_+tmp432_;
   double tmp434_ = tmp420_*tmp19_;
   double tmp435_ = tmp434_+tmp157_;
   double tmp436_ = (tmp435_)*(tmp86_);
   double tmp437_ = tmp155_+tmp436_;
   double tmp438_ = tmp420_*tmp146_;
   double tmp439_ = tmp438_+tmp162_;
   double tmp440_ = tmp437_+tmp439_;
   double tmp441_ = -(tmp67_);
   double tmp442_ = tmp441_*tmp4_;
   double tmp443_ = tmp240_*tmp16_;
   double tmp444_ = tmp67_*(tmp66_);
   double tmp445_ = tmp443_*tmp15_;
   double tmp446_ = tmp445_*(tmp86_);
   double tmp447_ = tmp444_+tmp446_;
   double tmp448_ = tmp443_*tmp19_;
   double tmp449_ = tmp447_+tmp448_;
   double tmp450_ = tmp441_*tmp14_;
   double tmp451_ = tmp443_*tmp14_;
   double tmp452_ = tmp451_*(tmp66_);
   double tmp453_ = tmp450_*tmp15_;
   double tmp454_ = tmp453_*(tmp86_);
   double tmp455_ = tmp452_+tmp454_;
   double tmp456_ = tmp450_*tmp19_;
   double tmp457_ = tmp455_+tmp456_;
   double tmp458_ = tmp443_*tmp4_;
   double tmp459_ = tmp458_*(tmp66_);
   double tmp460_ = tmp442_*tmp15_;
   double tmp461_ = tmp460_*(tmp86_);
   double tmp462_ = tmp459_+tmp461_;
   double tmp463_ = tmp442_*tmp19_;
   double tmp464_ = tmp462_+tmp463_;
   double tmp465_ = tmp240_*tmp15_;
   double tmp466_ = tmp19_*tmp67_;
   double tmp467_ = tmp466_*(tmp86_);
   double tmp468_ = tmp465_*tmp67_;
   double tmp469_ = tmp467_+tmp468_;
   double tmp470_ = -(tmp19_);
   double tmp471_ = tmp465_*tmp145_;
   double tmp472_ = tmp19_*tmp147_;
   double tmp473_ = tmp471_+tmp472_;
   double tmp474_ = (tmp473_)*(tmp86_);
   double tmp475_ = tmp470_*tmp145_;
   double tmp476_ = tmp465_*tmp147_;
   double tmp477_ = tmp475_+tmp476_;
   double tmp478_ = tmp474_+tmp477_;
   double tmp479_ = tmp465_*tmp14_;
   double tmp480_ = tmp19_*tmp18_;
   double tmp481_ = tmp479_+tmp480_;
   double tmp482_ = (tmp481_)*(tmp86_);
   double tmp483_ = tmp470_*tmp14_;
   double tmp484_ = tmp465_*tmp18_;
   double tmp485_ = tmp483_+tmp484_;
   double tmp486_ = tmp482_+tmp485_;
   double tmp487_ = (tmp186_)*(tmp153_);
   double tmp488_ = (tmp141_)*(tmp175_);
   double tmp489_ = tmp487_-tmp488_;
   double tmp490_ = (tmp489_)*(tmp200_);
   double tmp491_ = (tmp141_)*(tmp197_);
   double tmp492_ = (tmp164_)*(tmp153_);
   double tmp493_ = tmp491_-tmp492_;
   double tmp494_ = (tmp493_)*(tmp203_);
   double tmp495_ = tmp490_+tmp494_;
   double tmp496_ = (tmp164_)*(tmp175_);
   double tmp497_ = (tmp186_)*(tmp197_);
   double tmp498_ = tmp496_-tmp497_;
   double tmp499_ = (tmp498_)*(tmp206_);
   double tmp500_ = tmp495_+tmp499_;
   double tmp501_ = tmp240_*(tmp200_);
   double tmp502_ = tmp240_*(tmp203_);
   double tmp503_ = tmp240_*(tmp206_);
   double tmp504_ = tmp240_*tmp111_;
   double tmp505_ = -(tmp133_);
   double tmp506_ = tmp504_*tmp134_;
   double tmp507_ = tmp504_*tmp110_;
   double tmp508_ = tmp507_+tmp190_;
   double tmp509_ = (tmp508_)*(tmp132_);
   double tmp510_ = tmp188_+tmp509_;
   double tmp511_ = tmp504_*tmp143_;
   double tmp512_ = tmp511_+tmp195_;
   double tmp513_ = tmp510_+tmp512_;
   double tmp514_ = tmp504_*tmp43_;
   double tmp515_ = tmp514_*(tmp108_);
   double tmp516_ = tmp505_*tmp110_;
   double tmp517_ = tmp506_*tmp113_;
   double tmp518_ = tmp516_+tmp517_;
   double tmp519_ = (tmp518_)*(tmp132_);
   double tmp520_ = tmp515_+tmp519_;
   double tmp521_ = tmp505_*tmp143_;
   double tmp522_ = tmp506_*tmp110_;
   double tmp523_ = tmp521_+tmp522_;
   double tmp524_ = tmp520_+tmp523_;
   double tmp525_ = tmp240_*tmp112_;
   double tmp526_ = -(tmp43_);
   double tmp527_ = tmp526_*tmp111_;
   double tmp528_ = tmp526_*tmp133_;
   double tmp529_ = tmp43_*(tmp108_);
   double tmp530_ = tmp525_*tmp113_;
   double tmp531_ = tmp530_*(tmp132_);
   double tmp532_ = tmp529_+tmp531_;
   double tmp533_ = tmp525_*tmp110_;
   double tmp534_ = tmp532_+tmp533_;
   double tmp535_ = tmp525_*tmp111_;
   double tmp536_ = tmp535_*(tmp108_);
   double tmp537_ = tmp527_*tmp113_;
   double tmp538_ = tmp537_*(tmp132_);
   double tmp539_ = tmp536_+tmp538_;
   double tmp540_ = tmp527_*tmp110_;
   double tmp541_ = tmp539_+tmp540_;
   double tmp542_ = tmp525_*tmp133_;
   double tmp543_ = tmp542_*(tmp108_);
   double tmp544_ = tmp528_*tmp113_;
   double tmp545_ = tmp544_*(tmp132_);
   double tmp546_ = tmp543_+tmp545_;
   double tmp547_ = tmp528_*tmp110_;
   double tmp548_ = tmp546_+tmp547_;
   double tmp549_ = tmp240_*tmp113_;
   double tmp550_ = -(tmp110_);
   double tmp551_ = tmp110_*tmp43_;
   double tmp552_ = tmp551_*(tmp132_);
   double tmp553_ = tmp549_*tmp43_;
   double tmp554_ = tmp552_+tmp553_;
   double tmp555_ = tmp549_*tmp133_;
   double tmp556_ = tmp110_*tmp135_;
   double tmp557_ = tmp555_+tmp556_;
   double tmp558_ = (tmp557_)*(tmp132_);
   double tmp559_ = tmp550_*tmp133_;
   double tmp560_ = tmp549_*tmp135_;
   double tmp561_ = tmp559_+tmp560_;
   double tmp562_ = tmp558_+tmp561_;
   double tmp563_ = tmp549_*tmp142_;
   double tmp564_ = tmp110_*tmp144_;
   double tmp565_ = tmp563_+tmp564_;
   double tmp566_ = (tmp565_)*(tmp132_);
   double tmp567_ = tmp550_*tmp142_;
   double tmp568_ = tmp549_*tmp144_;
   double tmp569_ = tmp567_+tmp568_;
   double tmp570_ = tmp566_+tmp569_;

  mVal[0] = (tmp500_)/tmp239_;

  mCompDer[0][0] = (((((tmp230_)*(tmp153_)+(tmp221_)*(tmp186_))-((tmp218_)*(tmp175_)+(tmp227_)*(tmp141_)))*(tmp200_)+(((tmp218_)*(tmp197_)+(tmp233_)*(tmp141_))-((tmp224_)*(tmp153_)+(tmp221_)*(tmp164_)))*(tmp203_)+(((tmp224_)*(tmp175_)+(tmp227_)*(tmp164_))-((tmp230_)*(tmp197_)+(tmp233_)*(tmp186_)))*(tmp206_))*tmp239_)/tmp249_;
  mCompDer[0][1] = ((((tmp247_*(tmp153_)+tmp244_*(tmp186_))-(tmp243_*(tmp175_)+tmp246_*(tmp141_)))*(tmp200_)+((tmp243_*(tmp197_)+tmp248_*(tmp141_))-(tmp245_*(tmp153_)+tmp244_*(tmp164_)))*(tmp203_)+((tmp245_*(tmp175_)+tmp246_*(tmp164_))-(tmp247_*(tmp197_)+tmp248_*(tmp186_)))*(tmp206_))*tmp239_)/tmp249_;
  mCompDer[0][2] = ((((tmp254_*(tmp153_)+tmp251_*(tmp186_))-(tmp250_*(tmp175_)+tmp253_*(tmp141_)))*(tmp200_)+((tmp250_*(tmp197_)+tmp255_*(tmp141_))-(tmp252_*(tmp153_)+tmp251_*(tmp164_)))*(tmp203_)+((tmp252_*(tmp175_)+tmp253_*(tmp164_))-(tmp254_*(tmp197_)+tmp255_*(tmp186_)))*(tmp206_))*tmp239_)/tmp249_;
  mCompDer[0][3] = ((((tmp264_*(tmp153_)+tmp261_*(tmp186_))-(tmp260_*(tmp175_)+tmp263_*(tmp141_)))*(tmp200_)+((tmp260_*(tmp197_)+tmp265_*(tmp141_))-(tmp262_*(tmp153_)+tmp261_*(tmp164_)))*(tmp203_)+((tmp262_*(tmp175_)+tmp263_*(tmp164_))-(tmp264_*(tmp197_)+tmp265_*(tmp186_)))*(tmp206_))*tmp239_)/tmp249_;
  mCompDer[0][4] = ((((tmp274_*(tmp153_)+tmp271_*(tmp186_))-(tmp270_*(tmp175_)+tmp273_*(tmp141_)))*(tmp200_)+((tmp270_*(tmp197_)+tmp275_*(tmp141_))-(tmp272_*(tmp153_)+tmp271_*(tmp164_)))*(tmp203_)+((tmp272_*(tmp175_)+tmp273_*(tmp164_))-(tmp274_*(tmp197_)+tmp275_*(tmp186_)))*(tmp206_))*tmp239_)/tmp249_;
  mCompDer[0][5] = ((((tmp284_*(tmp153_)+tmp281_*(tmp186_))-(tmp280_*(tmp175_)+tmp283_*(tmp141_)))*(tmp200_)+((tmp280_*(tmp197_)+tmp285_*(tmp141_))-(tmp282_*(tmp153_)+tmp281_*(tmp164_)))*(tmp203_)+((tmp282_*(tmp175_)+tmp283_*(tmp164_))-(tmp284_*(tmp197_)+tmp285_*(tmp186_)))*(tmp206_))*tmp239_)/tmp249_;
  mCompDer[0][6] = ((((tmp294_*(tmp153_)+tmp291_*(tmp186_))-(tmp290_*(tmp175_)+tmp293_*(tmp141_)))*(tmp200_)+((tmp290_*(tmp197_)+tmp295_*(tmp141_))-(tmp292_*(tmp153_)+tmp291_*(tmp164_)))*(tmp203_)+((tmp292_*(tmp175_)+tmp293_*(tmp164_))-(tmp294_*(tmp197_)+tmp295_*(tmp186_)))*(tmp206_))*tmp239_)/tmp249_;
  mCompDer[0][7] = ((((tmp304_*(tmp153_)+tmp301_*(tmp186_))-(tmp300_*(tmp175_)+tmp303_*(tmp141_)))*(tmp200_)+((tmp300_*(tmp197_)+tmp305_*(tmp141_))-(tmp302_*(tmp153_)+tmp301_*(tmp164_)))*(tmp203_)+((tmp302_*(tmp175_)+tmp303_*(tmp164_))-(tmp304_*(tmp197_)+tmp305_*(tmp186_)))*(tmp206_))*tmp239_)/tmp249_;
  mCompDer[0][8] = ((((tmp314_*(tmp153_)+tmp311_*(tmp186_))-(tmp310_*(tmp175_)+tmp313_*(tmp141_)))*(tmp200_)+((tmp310_*(tmp197_)+tmp315_*(tmp141_))-(tmp312_*(tmp153_)+tmp311_*(tmp164_)))*(tmp203_)+((tmp312_*(tmp175_)+tmp313_*(tmp164_))-(tmp314_*(tmp197_)+tmp315_*(tmp186_)))*(tmp206_))*tmp239_)/tmp249_;
  mCompDer[0][9] = ((((tmp324_*(tmp153_)+tmp321_*(tmp186_))-(tmp320_*(tmp175_)+tmp323_*(tmp141_)))*(tmp200_)+((tmp320_*(tmp197_)+tmp325_*(tmp141_))-(tmp322_*(tmp153_)+tmp321_*(tmp164_)))*(tmp203_)+((tmp322_*(tmp175_)+tmp323_*(tmp164_))-(tmp324_*(tmp197_)+tmp325_*(tmp186_)))*(tmp206_))*tmp239_)/tmp249_;
  mCompDer[0][10] = ((((tmp330_*(tmp153_)+tmp327_*(tmp186_))-(tmp326_*(tmp175_)+tmp329_*(tmp141_)))*(tmp200_)+((tmp326_*(tmp197_)+tmp331_*(tmp141_))-(tmp328_*(tmp153_)+tmp327_*(tmp164_)))*(tmp203_)+((tmp328_*(tmp175_)+tmp329_*(tmp164_))-(tmp330_*(tmp197_)+tmp331_*(tmp186_)))*(tmp206_))*tmp239_)/tmp249_;
  mCompDer[0][11] = ((((tmp340_*(tmp153_)+tmp337_*(tmp186_))-(tmp336_*(tmp175_)+tmp339_*(tmp141_)))*(tmp200_)+((tmp336_*(tmp197_)+tmp341_*(tmp141_))-(tmp338_*(tmp153_)+tmp337_*(tmp164_)))*(tmp203_)+((tmp338_*(tmp175_)+tmp339_*(tmp164_))-(tmp340_*(tmp197_)+tmp341_*(tmp186_)))*(tmp206_))*tmp239_)/tmp249_;
  mCompDer[0][12] = ((((tmp346_*(tmp153_)+tmp343_*(tmp186_))-(tmp342_*(tmp175_)+tmp345_*(tmp141_)))*(tmp200_)+((tmp342_*(tmp197_)+tmp347_*(tmp141_))-(tmp344_*(tmp153_)+tmp343_*(tmp164_)))*(tmp203_)+((tmp344_*(tmp175_)+tmp345_*(tmp164_))-(tmp346_*(tmp197_)+tmp347_*(tmp186_)))*(tmp206_))*tmp239_)/tmp249_;
  mCompDer[0][13] = ((((tmp352_*(tmp153_)+tmp349_*(tmp186_))-(tmp348_*(tmp175_)+tmp351_*(tmp141_)))*(tmp200_)+((tmp348_*(tmp197_)+tmp353_*(tmp141_))-(tmp350_*(tmp153_)+tmp349_*(tmp164_)))*(tmp203_)+((tmp350_*(tmp175_)+tmp351_*(tmp164_))-(tmp352_*(tmp197_)+tmp353_*(tmp186_)))*(tmp206_))*tmp239_)/tmp249_;
  mCompDer[0][14] = ((((tmp358_*(tmp153_)+tmp355_*(tmp186_))-(tmp354_*(tmp175_)+tmp357_*(tmp141_)))*(tmp200_)+((tmp354_*(tmp197_)+tmp359_*(tmp141_))-(tmp356_*(tmp153_)+tmp355_*(tmp164_)))*(tmp203_)+((tmp356_*(tmp175_)+tmp357_*(tmp164_))-(tmp358_*(tmp197_)+tmp359_*(tmp186_)))*(tmp206_))*tmp239_)/tmp249_;
  mCompDer[0][15] = (((((tmp386_)*(tmp153_)+(tmp377_)*(tmp186_))-((tmp374_)*(tmp175_)+(tmp383_)*(tmp141_)))*(tmp200_)+(((tmp374_)*(tmp197_)+(tmp389_)*(tmp141_))-((tmp380_)*(tmp153_)+(tmp377_)*(tmp164_)))*(tmp203_)+(((tmp380_)*(tmp175_)+(tmp383_)*(tmp164_))-((tmp386_)*(tmp197_)+(tmp389_)*(tmp186_)))*(tmp206_))*tmp239_)/tmp249_;
  mCompDer[0][16] = (((((tmp416_)*(tmp153_)+(tmp407_)*(tmp186_))-((tmp404_)*(tmp175_)+(tmp413_)*(tmp141_)))*(tmp200_)+(((tmp404_)*(tmp197_)+(tmp419_)*(tmp141_))-((tmp410_)*(tmp153_)+(tmp407_)*(tmp164_)))*(tmp203_)+(((tmp410_)*(tmp175_)+(tmp413_)*(tmp164_))-((tmp416_)*(tmp197_)+(tmp419_)*(tmp186_)))*(tmp206_))*tmp239_)/tmp249_;
  mCompDer[0][17] = (((tmp440_)*(tmp153_)*(tmp200_)+-((tmp433_)*(tmp153_))*(tmp203_)+((tmp433_)*(tmp175_)-(tmp440_)*(tmp197_))*(tmp206_))*tmp239_)/tmp249_;
  mCompDer[0][18] = ((((tmp464_)*(tmp153_)-(tmp449_)*(tmp175_))*(tmp200_)+((tmp449_)*(tmp197_)-(tmp457_)*(tmp153_))*(tmp203_)+((tmp457_)*(tmp175_)-(tmp464_)*(tmp197_))*(tmp206_))*tmp239_)/tmp249_;
  mCompDer[0][19] = ((((tmp486_)*(tmp153_)-(tmp469_)*(tmp175_))*(tmp200_)+((tmp469_)*(tmp197_)-(tmp478_)*(tmp153_))*(tmp203_)+((tmp478_)*(tmp175_)-(tmp486_)*(tmp197_))*(tmp206_))*tmp239_)/tmp249_;
  mCompDer[0][20] = (tmp240_*(tmp489_)*tmp239_-(tmp500_)*((0.500000*(tmp501_+tmp501_))/tmp239_))/tmp249_;
  mCompDer[0][21] = (tmp240_*(tmp493_)*tmp239_-(tmp500_)*((0.500000*(tmp502_+tmp502_))/tmp239_))/tmp249_;
  mCompDer[0][22] = (tmp240_*(tmp498_)*tmp239_-(tmp500_)*((0.500000*(tmp503_+tmp503_))/tmp239_))/tmp249_;
  mCompDer[0][23] = ((-((tmp513_)*(tmp141_))*(tmp200_)+(tmp524_)*(tmp141_)*(tmp203_)+((tmp513_)*(tmp164_)-(tmp524_)*(tmp186_))*(tmp206_))*tmp239_)/tmp249_;
  mCompDer[0][24] = ((((tmp534_)*(tmp186_)-(tmp541_)*(tmp141_))*(tmp200_)+((tmp548_)*(tmp141_)-(tmp534_)*(tmp164_))*(tmp203_)+((tmp541_)*(tmp164_)-(tmp548_)*(tmp186_))*(tmp206_))*tmp239_)/tmp249_;
  mCompDer[0][25] = ((((tmp554_)*(tmp186_)-(tmp562_)*(tmp141_))*(tmp200_)+((tmp570_)*(tmp141_)-(tmp554_)*(tmp164_))*(tmp203_)+((tmp562_)*(tmp164_)-(tmp570_)*(tmp186_))*(tmp206_))*tmp239_)/tmp249_;
  mCompDer[0][26] = ((tmp489_)*tmp239_-(tmp500_)*((0.500000*(tmp200_+tmp200_))/tmp239_))/tmp249_;
  mCompDer[0][27] = ((tmp493_)*tmp239_-(tmp500_)*((0.500000*(tmp203_+tmp203_))/tmp239_))/tmp249_;
  mCompDer[0][28] = ((tmp498_)*tmp239_-(tmp500_)*((0.500000*(tmp206_+tmp206_))/tmp239_))/tmp249_;
}


void cEqCoplanDCBrownId::ComputeValDerivHessian()
{
  ELISE_ASSERT(false,"Foncteur cEqCoplanDCBrownId Has no Der Sec");
}

void cEqCoplanDCBrownId::SetDCBrown_State_0_0(double aVal){ mLocDCBrown_State_0_0 = aVal;}
void cEqCoplanDCBrownId::SetDCBrown_State_0_1(double aVal){ mLocDCBrown_State_0_1 = aVal;}
void cEqCoplanDCBrownId::SetXL1(double aVal){ mLocXL1 = aVal;}
void cEqCoplanDCBrownId::SetXL2(double aVal){ mLocXL2 = aVal;}
void cEqCoplanDCBrownId::SetYL1(double aVal){ mLocYL1 = aVal;}
void cEqCoplanDCBrownId::SetYL2(double aVal){ mLocYL2 = aVal;}



double * cEqCoplanDCBrownId::AdrVarLocFromString(const std::string & aName)
{
   if (aName == "DCBrown_State_0_0") return & mLocDCBrown_State_0_0;
   if (aName == "DCBrown_State_0_1") return & mLocDCBrown_State_0_1;
   if (aName == "XL1") return & mLocXL1;
   if (aName == "XL2") return & mLocXL2;
   if (aName == "YL1") return & mLocYL1;
   if (aName == "YL2") return & mLocYL2;
   return 0;
}


cElCompiledFonc::cAutoAddEntry cEqCoplanDCBrownId::mTheAuto("cEqCoplanDCBrownId",cEqCoplanDCBrownId::Alloc);


cElCompiledFonc *  cEqCoplanDCBrownId::Alloc()
{  return new cEqCoplanDCBrownId();
}

