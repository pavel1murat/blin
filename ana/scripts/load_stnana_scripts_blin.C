#include "TInterpreter.h"
#include "blin/ana/scripts/modules.hh"
int load_stnana_scripts_blin() {
//-----------------------------------------------------------------------------
// the first parameter is the script, the second - env.var telling whether 
// the script has to be loaded. If the corresponding env. variable is not defined,
// the script is not loaded. PWD is always defined
//-----------------------------------------------------------------------------
  char        macro[200];

  const char* script[] = { 
    "trk.C"       , "PWD",
    0 
  };

  TString work_dir = gEnv->GetValue("Stnana.TestReleaseDir",gSystem->Getenv("PWD"));

  TInterpreter* cint = gROOT->GetInterpreter();
  
  for (int i=0; script[i] != 0; i+=2) {
    const char* dir = gSystem->Getenv(script[i+1]);
    if (dir) {
      sprintf(macro,"%s/blin/ana/scripts/%s",dir,script[i]);
      if (! cint->IsLoaded(macro)) cint->LoadMacro(macro);
    }
  }
  
  return 0;
}
