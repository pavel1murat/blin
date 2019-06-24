///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
#include "Stntuple/scripts/global_vars.h"
#include "blin/ana/scripts/modules.hh"
def_name trk_001("trk_ana");

void trk_ana(int PdgCode = 11, int GeneratorCode = 2) {
//-----------------------------------------------------------------------------
// configure validation module
//-----------------------------------------------------------------------------
  m_trk = (TMyTrackAnaModule*) g.x->AddModule("TMyTrackAnaModule",0);  
  m_trk->SetPdgCode      (PdgCode);
  m_trk->SetGeneratorCode(GeneratorCode);
}
