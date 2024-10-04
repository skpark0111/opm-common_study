
#include <opm/input/eclipse/Deck/UDAValue.hpp>
#include <opm/input/eclipse/Parser/ParserItem.hpp>
#include <opm/input/eclipse/Parser/ParserRecord.hpp>
#include <opm/input/eclipse/Parser/Parser.hpp>





#include <opm/input/eclipse/Parser/ParserKeywords/B.hpp>
namespace Opm {
namespace ParserKeywords {
BC::BC() : ParserKeyword("BC", KeywordSize(SLASH_TERMINATED)) {
  addValidSectionName("SOLUTION");
  clearDeckNames();
  addDeckName("BC");
  {
     ParserRecord record;
     {
        ParserItem item("I1", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("I2", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("J1", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("J2", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("K1", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("K2", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("DIRECTION", ParserItem::itype::STRING);
        record.addItem(item);
     }
     {
        ParserItem item("TYPE", ParserItem::itype::STRING);
        record.addItem(item);
     }
     {
        ParserItem item("COMPONENT", ParserItem::itype::STRING);
        item.setDefault( std::string("NONE") );
        record.addItem(item);
     }
     {
        ParserItem item("RATE", ParserItem::itype::DOUBLE);
        item.setDefault( double(0) );
        item.push_backDimension("Mass/Time*Length*Length");
        record.addItem(item);
     }
     {
        ParserItem item("PRESSURE", ParserItem::itype::DOUBLE);
        item.setDefault( double(1.000000) );
        item.push_backDimension("Pressure");
        record.addItem(item);
     }
     {
        ParserItem item("TEMPERATURE", ParserItem::itype::DOUBLE);
        item.push_backDimension("Temperature");
        record.addItem(item);
     }
     addRecord( record );
  }
}
const std::string BC::keywordName = "BC";
const std::string BC::I1::itemName = "I1";
const std::string BC::I2::itemName = "I2";
const std::string BC::J1::itemName = "J1";
const std::string BC::J2::itemName = "J2";
const std::string BC::K1::itemName = "K1";
const std::string BC::K2::itemName = "K2";
const std::string BC::DIRECTION::itemName = "DIRECTION";
const std::string BC::TYPE::itemName = "TYPE";
const std::string BC::COMPONENT::itemName = "COMPONENT";
const std::string BC::COMPONENT::defaultValue = "NONE";
const std::string BC::RATE::itemName = "RATE";
const std::string BC::PRESSURE::itemName = "PRESSURE";
const std::string BC::TEMPERATURE::itemName = "TEMPERATURE";


BCCON::BCCON() : ParserKeyword("BCCON", KeywordSize(SLASH_TERMINATED)) {
  addValidSectionName("GRID");
  clearDeckNames();
  addDeckName("BCCON");
  {
     ParserRecord record;
     {
        ParserItem item("INDEX", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("I1", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("I2", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("J1", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("J2", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("K1", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("K2", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("DIRECTION", ParserItem::itype::STRING);
        record.addItem(item);
     }
     addRecord( record );
  }
}
const std::string BCCON::keywordName = "BCCON";
const std::string BCCON::INDEX::itemName = "INDEX";
const std::string BCCON::I1::itemName = "I1";
const std::string BCCON::I2::itemName = "I2";
const std::string BCCON::J1::itemName = "J1";
const std::string BCCON::J2::itemName = "J2";
const std::string BCCON::K1::itemName = "K1";
const std::string BCCON::K2::itemName = "K2";
const std::string BCCON::DIRECTION::itemName = "DIRECTION";


BCPROP::BCPROP() : ParserKeyword("BCPROP", KeywordSize(SLASH_TERMINATED)) {
  addValidSectionName("SCHEDULE");
  clearDeckNames();
  addDeckName("BCPROP");
  {
     ParserRecord record;
     {
        ParserItem item("INDEX", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("TYPE", ParserItem::itype::STRING);
        record.addItem(item);
     }
     {
        ParserItem item("COMPONENT", ParserItem::itype::STRING);
        item.setDefault( std::string("NONE") );
        record.addItem(item);
     }
     {
        ParserItem item("RATE", ParserItem::itype::DOUBLE);
        item.setDefault( double(0) );
        item.push_backDimension("Mass/Time*Length*Length");
        record.addItem(item);
     }
     {
        ParserItem item("PRESSURE", ParserItem::itype::DOUBLE);
        item.setDefault( double(1.000000) );
        item.push_backDimension("Pressure");
        record.addItem(item);
     }
     {
        ParserItem item("TEMPERATURE", ParserItem::itype::DOUBLE);
        item.push_backDimension("Temperature");
        record.addItem(item);
     }
     {
        ParserItem item("MECHTYPE", ParserItem::itype::STRING);
        item.setDefault( std::string("NONE") );
        record.addItem(item);
     }
     {
        ParserItem item("FIXEDX", ParserItem::itype::INT);
        item.setDefault( 1 );
        record.addItem(item);
     }
     {
        ParserItem item("FIXEDY", ParserItem::itype::INT);
        item.setDefault( 1 );
        record.addItem(item);
     }
     {
        ParserItem item("FIXEDZ", ParserItem::itype::INT);
        item.setDefault( 1 );
        record.addItem(item);
     }
     {
        ParserItem item("STRESSXX", ParserItem::itype::DOUBLE);
        item.setDefault( double(0) );
        item.push_backDimension("Pressure");
        record.addItem(item);
     }
     {
        ParserItem item("STRESSYY", ParserItem::itype::DOUBLE);
        item.setDefault( double(0) );
        item.push_backDimension("Pressure");
        record.addItem(item);
     }
     {
        ParserItem item("STRESSZZ", ParserItem::itype::DOUBLE);
        item.setDefault( double(0) );
        item.push_backDimension("Pressure");
        record.addItem(item);
     }
     {
        ParserItem item("DISPX", ParserItem::itype::DOUBLE);
        item.setDefault( double(0) );
        item.push_backDimension("Length");
        record.addItem(item);
     }
     {
        ParserItem item("DISPY", ParserItem::itype::DOUBLE);
        item.setDefault( double(0) );
        item.push_backDimension("Length");
        record.addItem(item);
     }
     {
        ParserItem item("DISPZ", ParserItem::itype::DOUBLE);
        item.setDefault( double(0) );
        item.push_backDimension("Length");
        record.addItem(item);
     }
     addRecord( record );
  }
}
const std::string BCPROP::keywordName = "BCPROP";
const std::string BCPROP::INDEX::itemName = "INDEX";
const std::string BCPROP::TYPE::itemName = "TYPE";
const std::string BCPROP::COMPONENT::itemName = "COMPONENT";
const std::string BCPROP::COMPONENT::defaultValue = "NONE";
const std::string BCPROP::RATE::itemName = "RATE";
const std::string BCPROP::PRESSURE::itemName = "PRESSURE";
const std::string BCPROP::TEMPERATURE::itemName = "TEMPERATURE";
const std::string BCPROP::MECHTYPE::itemName = "MECHTYPE";
const std::string BCPROP::MECHTYPE::defaultValue = "NONE";
const std::string BCPROP::FIXEDX::itemName = "FIXEDX";
const std::string BCPROP::FIXEDY::itemName = "FIXEDY";
const std::string BCPROP::FIXEDZ::itemName = "FIXEDZ";
const std::string BCPROP::STRESSXX::itemName = "STRESSXX";
const std::string BCPROP::STRESSYY::itemName = "STRESSYY";
const std::string BCPROP::STRESSZZ::itemName = "STRESSZZ";
const std::string BCPROP::DISPX::itemName = "DISPX";
const std::string BCPROP::DISPY::itemName = "DISPY";
const std::string BCPROP::DISPZ::itemName = "DISPZ";


BDENSITY::BDENSITY() : ParserKeyword("BDENSITY", KeywordSize("TABDIMS", "NTPVT", false, 0)) {
  addValidSectionName("PROPS");
  clearDeckNames();
  addDeckName("BDENSITY");
  {
     ParserRecord record;
     {
        ParserItem item("BRINE_DENSITY", ParserItem::itype::DOUBLE);
        item.setSizeType(ParserItem::item_size::ALL);
        item.push_backDimension("Density");
        record.addItem(item);
     }
     addRecord( record );
  }
}
const std::string BDENSITY::keywordName = "BDENSITY";
const std::string BDENSITY::BRINE_DENSITY::itemName = "BRINE_DENSITY";


BGGI::BGGI() : ParserKeyword("BGGI", KeywordSize("TABDIMS", "NTPVT", false, 0)) {
  addValidSectionName("PROPS");
  clearDeckNames();
  addDeckName("BGGI");
  {
     ParserRecord record;
     {
        ParserItem item("GAS_PRESSURE", ParserItem::itype::DOUBLE);
        item.push_backDimension("Pressure");
        record.addItem(item);
     }
     {
        ParserItem item("DATA", ParserItem::itype::DOUBLE);
        item.setSizeType(ParserItem::item_size::ALL);
        item.push_backDimension("1");
        record.addItem(item);
     }
     addRecord( record );
  }
}
const std::string BGGI::keywordName = "BGGI";
const std::string BGGI::GAS_PRESSURE::itemName = "GAS_PRESSURE";
const std::string BGGI::DATA::itemName = "DATA";


BIC::BIC() : ParserKeyword("BIC", KeywordSize("TABDIMS", "NUM_EOS_RES", false, 0)) {
  addValidSectionName("PROPS");
  clearDeckNames();
  addDeckName("BIC");
  {
     ParserRecord record;
     {
        ParserItem item("DATA", ParserItem::itype::DOUBLE);
        item.setSizeType(ParserItem::item_size::ALL);
        item.setDefault( double(0) );
        item.push_backDimension("1");
        record.addItem(item);
     }
     addRecord( record );
  }
}
const std::string BIC::keywordName = "BIC";
const std::string BIC::DATA::itemName = "DATA";


BIGMODEL::BIGMODEL() : ParserKeyword("BIGMODEL", KeywordSize(0, false)) {
  addValidSectionName("RUNSPEC");
  clearDeckNames();
  addDeckName("BIGMODEL");
}
const std::string BIGMODEL::keywordName = "BIGMODEL";


BIOTCOEF::BIOTCOEF() : ParserKeyword("BIOTCOEF", KeywordSize(1, false)) {
  addValidSectionName("GRID");
  clearDeckNames();
  addDeckName("BIOTCOEF");
  {
     ParserRecord record;
     {
        ParserItem item("data", ParserItem::itype::DOUBLE);
        item.setSizeType(ParserItem::item_size::ALL);
        item.push_backDimension("1");
        record.addDataItem(item);
     }
     addDataRecord( record );
  }
}
const std::string BIOTCOEF::keywordName = "BIOTCOEF";
const std::string BIOTCOEF::data::itemName = "data";


BLACKOIL::BLACKOIL() : ParserKeyword("BLACKOIL", KeywordSize(0, false)) {
  addValidSectionName("RUNSPEC");
  clearDeckNames();
  addDeckName("BLACKOIL");
}
const std::string BLACKOIL::keywordName = "BLACKOIL";


BLOCK_PROBE::BLOCK_PROBE() : ParserKeyword("BLOCK_PROBE", KeywordSize(SLASH_TERMINATED)) {
  addValidSectionName("SUMMARY");
  clearDeckNames();
  addDeckName("BTPADALK");
  addDeckName("BGIPL");
  addDeckName("BGPR");
  addDeckName("BWPR");
  addDeckName("BVELGI");
  addDeckName("BPORVMOD");
  addDeckName("BOIPL");
  addDeckName("BPPC");
  addDeckName("BFLOGJ");
  addDeckName("BFLOGI");
  addDeckName("BRVSAT");
  addDeckName("BEWV_SAL");
  addDeckName("BPBUB");
  addDeckName("BFLOGK");
  addDeckName("BESALSUR");
  addDeckName("BKROW");
  addDeckName("BVGAS");
  addDeckName("BWSHY");
  addDeckName("BGIPG");
  addDeckName("BGTRP");
  addDeckName("BWPV");
  addDeckName("BVELGK");
  addDeckName("BSGAS");
  addDeckName("BRSSAT");
  addDeckName("BOKR");
  addDeckName("BSTATE");
  addDeckName("BFLOOJ");
  addDeckName("BTIPTSUR");
  addDeckName("BVELWI");
  addDeckName("BODEN");
  addDeckName("BDENG");
  addDeckName("BWIP");
  addDeckName("BOVIS");
  addDeckName("BVOIL");
  addDeckName("BOIP");
  addDeckName("BVELOI");
  addDeckName("BPPO");
  addDeckName("BSCN_X");
  addDeckName("BGI");
  addDeckName("BVELOJ");
  addDeckName("BNKR");
  addDeckName("BDENW");
  addDeckName("BDENO");
  addDeckName("BSOIL");
  addDeckName("BGSTRP");
  addDeckName("LBCTRA_X");
  addDeckName("BWDEN");
  addDeckName("BWSAT");
  addDeckName("BTSTMALK");
  addDeckName("BHD");
  addDeckName("BNSAT");
  addDeckName("BPPW");
  addDeckName("BFLOWK");
  addDeckName("BSWAT");
  addDeckName("BKRG");
  addDeckName("BTSADCAT");
  addDeckName("BRS");
  addDeckName("BTSADALK");
  addDeckName("BTSTSUR");
  addDeckName("BOIPG");
  addDeckName("BVWAT");
  addDeckName("BOPV");
  addDeckName("BTCNFCAT");
  addDeckName("BTADSFOA");
  addDeckName("BPPG");
  addDeckName("BTDCYFOA");
  addDeckName("BFLOWI");
  addDeckName("BPR");
  addDeckName("BFLOOK");
  addDeckName("BRV");
  addDeckName("BFLOWJ");
  addDeckName("BVELGJ");
  addDeckName("BTHLFFOA");
  addDeckName("BVELWJ");
  addDeckName("BVELWK");
  addDeckName("BGKR");
  addDeckName("BKRO");
  addDeckName("BCSC");
  addDeckName("BKROG");
  addDeckName("BHPV");
  addDeckName("BTADSALK");
  addDeckName("BWPC");
  addDeckName("BGPC");
  addDeckName("BFLOOI");
  addDeckName("BPR_X");
  addDeckName("BPDEW");
  addDeckName("BKRW");
  addDeckName("BGTPD");
  addDeckName("BSIP");
  addDeckName("BGSHY");
  addDeckName("BWVIS");
  addDeckName("BEWV_SUR");
  addDeckName("BWSMA");
  addDeckName("BCAD");
  addDeckName("BTADSUR");
  addDeckName("BHDF");
  addDeckName("BCTRA_X");
  addDeckName("BHD_X");
  addDeckName("BNIP");
  addDeckName("BHDF_X");
  addDeckName("LBPR_X");
  addDeckName("LBHD_X");
  addDeckName("BTCASUR");
  addDeckName("BGIP");
  addDeckName("LBHDF_X");
  addDeckName("LBSCN_X");
  addDeckName("BRPV");
  addDeckName("BGVIS");
  addDeckName("BGPV");
  addDeckName("BRTM");
  addDeckName("BPERMMOD");
  addDeckName("BWKR");
  addDeckName("BAPI");
  addDeckName("BSCN");
  addDeckName("BVELOK");
  addDeckName("BTRADCAT");
  addDeckName("BGSAT");
  addDeckName("BESALPLY");
  addDeckName("BTIPTHEA");
  addDeckName("BCGC");
  addDeckName("BGDEN");
  addDeckName("BTCNFFOA");
  addDeckName("BTCNFHEA");
  addDeckName("BTCNMFOA");
  addDeckName("BOSAT");
  addDeckName("BTMOBFOA");
  addDeckName("BTCNFANI");
  addDeckName("BTCNFSUR");
  addDeckName("BTIPTFOA");
  addDeckName("BTCNFALK");
  setMatchRegex("BU.+|BTIPF.+|BTIPS.+|BTCNF.+|BTCNS.+|BTCN[1-9][0-9]*.+|BTIPT.+|BTIPF.+|BTIPS.+|BTIP[1-9][0-9]*.+|BTADS.+|BTDCY");
  {
     ParserRecord record;
     {
        ParserItem item("I", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("J", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("K", ParserItem::itype::INT);
        record.addItem(item);
     }
     addRecord( record );
  }
}
const std::string BLOCK_PROBE::keywordName = "BLOCK_PROBE";
const std::string BLOCK_PROBE::I::itemName = "I";
const std::string BLOCK_PROBE::J::itemName = "J";
const std::string BLOCK_PROBE::K::itemName = "K";


BLOCK_PROBE300::BLOCK_PROBE300() : ParserKeyword("BLOCK_PROBE300", KeywordSize(SLASH_TERMINATED)) {
  addValidSectionName("SUMMARY");
  clearDeckNames();
  addDeckName("BTEMP");
  {
     ParserRecord record;
     {
        ParserItem item("I", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("J", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("K", ParserItem::itype::INT);
        record.addItem(item);
     }
     addRecord( record );
  }
}
const std::string BLOCK_PROBE300::keywordName = "BLOCK_PROBE300";
const std::string BLOCK_PROBE300::I::itemName = "I";
const std::string BLOCK_PROBE300::J::itemName = "J";
const std::string BLOCK_PROBE300::K::itemName = "K";


BOGI::BOGI() : ParserKeyword("BOGI", KeywordSize("TABDIMS", "NTPVT", false, 0)) {
  addValidSectionName("PROPS");
  clearDeckNames();
  addDeckName("BOGI");
  {
     ParserRecord record;
     {
        ParserItem item("OIL_PRESSURE", ParserItem::itype::DOUBLE);
        item.push_backDimension("Pressure");
        record.addItem(item);
     }
     {
        ParserItem item("DATA", ParserItem::itype::DOUBLE);
        item.setSizeType(ParserItem::item_size::ALL);
        item.push_backDimension("1");
        record.addItem(item);
     }
     addRecord( record );
  }
}
const std::string BOGI::keywordName = "BOGI";
const std::string BOGI::OIL_PRESSURE::itemName = "OIL_PRESSURE";
const std::string BOGI::DATA::itemName = "DATA";


BOUNDARY::BOUNDARY() : ParserKeyword("BOUNDARY", KeywordSize(1, false)) {
  addValidSectionName("SCHEDULE");
  addValidSectionName("REGIONS");
  addValidSectionName("SOLUTION");
  addValidSectionName("EDIT");
  addValidSectionName("GRID");
  clearDeckNames();
  addDeckName("BOUNDARY");
  {
     ParserRecord record;
     {
        ParserItem item("IX1", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("IX2", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("JY1", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("JY2", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("KZ1", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("KZ2", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("ORIENTATION_INDEX", ParserItem::itype::INT);
        item.setDefault( 1 );
        record.addItem(item);
     }
     {
        ParserItem item("DUAL_PORO_FLAG", ParserItem::itype::STRING);
        item.setDefault( std::string("BOTH") );
        record.addItem(item);
     }
     addRecord( record );
  }
}
const std::string BOUNDARY::keywordName = "BOUNDARY";
const std::string BOUNDARY::IX1::itemName = "IX1";
const std::string BOUNDARY::IX2::itemName = "IX2";
const std::string BOUNDARY::JY1::itemName = "JY1";
const std::string BOUNDARY::JY2::itemName = "JY2";
const std::string BOUNDARY::KZ1::itemName = "KZ1";
const std::string BOUNDARY::KZ2::itemName = "KZ2";
const std::string BOUNDARY::ORIENTATION_INDEX::itemName = "ORIENTATION_INDEX";
const std::string BOUNDARY::DUAL_PORO_FLAG::itemName = "DUAL_PORO_FLAG";
const std::string BOUNDARY::DUAL_PORO_FLAG::defaultValue = "BOTH";


BOX::BOX() : ParserKeyword("BOX", KeywordSize(1, false)) {
  addValidSectionName("SCHEDULE");
  addValidSectionName("REGIONS");
  addValidSectionName("PROPS");
  addValidSectionName("SOLUTION");
  addValidSectionName("EDIT");
  addValidSectionName("GRID");
  clearDeckNames();
  addDeckName("BOX");
  {
     ParserRecord record;
     {
        ParserItem item("I1", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("I2", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("J1", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("J2", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("K1", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("K2", ParserItem::itype::INT);
        record.addItem(item);
     }
     addRecord( record );
  }
}
const std::string BOX::keywordName = "BOX";
const std::string BOX::I1::itemName = "I1";
const std::string BOX::I2::itemName = "I2";
const std::string BOX::J1::itemName = "J1";
const std::string BOX::J2::itemName = "J2";
const std::string BOX::K1::itemName = "K1";
const std::string BOX::K2::itemName = "K2";


BPARA::BPARA() : ParserKeyword("BPARA", KeywordSize(0, false)) {
  addValidSectionName("RUNSPEC");
  clearDeckNames();
  addDeckName("BPARA");
}
const std::string BPARA::keywordName = "BPARA";


BPIDIMS::BPIDIMS() : ParserKeyword("BPIDIMS", KeywordSize(1, false)) {
  addValidSectionName("RUNSPEC");
  clearDeckNames();
  addDeckName("BPIDIMS");
  {
     ParserRecord record;
     {
        ParserItem item("MXNBIP", ParserItem::itype::INT);
        item.setDefault( 10 );
        record.addItem(item);
     }
     {
        ParserItem item("MXNLBI", ParserItem::itype::INT);
        item.setDefault( 1 );
        record.addItem(item);
     }
     addRecord( record );
  }
}
const std::string BPIDIMS::keywordName = "BPIDIMS";
const std::string BPIDIMS::MXNBIP::itemName = "MXNBIP";
const std::string BPIDIMS::MXNLBI::itemName = "MXNLBI";


BRANPROP::BRANPROP() : ParserKeyword("BRANPROP", KeywordSize(SLASH_TERMINATED)) {
  addValidSectionName("SCHEDULE");
  setProhibitedKeywords({
    "GRUPNET",
  });
  setRequiredKeywords({
    "NETWORK",
  });
  clearDeckNames();
  addDeckName("BRANPROP");
  {
     ParserRecord record;
     {
        ParserItem item("DOWNTREE_NODE", ParserItem::itype::STRING);
        record.addItem(item);
     }
     {
        ParserItem item("UPTREE_NODE", ParserItem::itype::STRING);
        record.addItem(item);
     }
     {
        ParserItem item("VFP_TABLE", ParserItem::itype::INT);
        record.addItem(item);
     }
     {
        ParserItem item("ALQ", ParserItem::itype::DOUBLE);
        item.setDefault( double(0) );
        record.addItem(item);
     }
     {
        ParserItem item("ALQ_SURFACE_DENSITY", ParserItem::itype::STRING);
        item.setDefault( std::string("NONE") );
        record.addItem(item);
     }
     addRecord( record );
  }
}
const std::string BRANPROP::keywordName = "BRANPROP";
const std::string BRANPROP::DOWNTREE_NODE::itemName = "DOWNTREE_NODE";
const std::string BRANPROP::UPTREE_NODE::itemName = "UPTREE_NODE";
const std::string BRANPROP::VFP_TABLE::itemName = "VFP_TABLE";
const std::string BRANPROP::ALQ::itemName = "ALQ";
const std::string BRANPROP::ALQ_SURFACE_DENSITY::itemName = "ALQ_SURFACE_DENSITY";
const std::string BRANPROP::ALQ_SURFACE_DENSITY::defaultValue = "NONE";


BRINE::BRINE() : ParserKeyword("BRINE", KeywordSize(0, 1, false)) {
  addValidSectionName("RUNSPEC");
  clearDeckNames();
  addDeckName("BRINE");
  {
     ParserRecord record;
     {
        ParserItem item("SALTS", ParserItem::itype::STRING);
        item.setSizeType(ParserItem::item_size::ALL);
        record.addItem(item);
     }
     addRecord( record );
  }
}
const std::string BRINE::keywordName = "BRINE";
const std::string BRINE::SALTS::itemName = "SALTS";


BTOBALFA::BTOBALFA() : ParserKeyword("BTOBALFA", KeywordSize(1, false)) {
  addValidSectionName("GRID");
  clearDeckNames();
  addDeckName("BTOBALFA");
  {
     ParserRecord record;
     {
        ParserItem item("VALUE", ParserItem::itype::DOUBLE);
        item.push_backDimension("1");
        record.addItem(item);
     }
     addRecord( record );
  }
}
const std::string BTOBALFA::keywordName = "BTOBALFA";
const std::string BTOBALFA::VALUE::itemName = "VALUE";


BTOBALFV::BTOBALFV() : ParserKeyword("BTOBALFV", KeywordSize(1, false)) {
  addValidSectionName("GRID");
  clearDeckNames();
  addDeckName("BTOBALFV");
  {
     ParserRecord record;
     {
        ParserItem item("data", ParserItem::itype::DOUBLE);
        item.setSizeType(ParserItem::item_size::ALL);
        item.push_backDimension("1");
        record.addDataItem(item);
     }
     addDataRecord( record );
  }
}
const std::string BTOBALFV::keywordName = "BTOBALFV";
const std::string BTOBALFV::data::itemName = "data";


}
}
