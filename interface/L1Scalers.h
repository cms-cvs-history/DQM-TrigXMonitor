#ifndef L1Scalers_H
#define L1Scalers_H

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "DQMServices/Core/interface/DaqMonitorBEInterface.h"
#include "DQMServices/Daemon/interface/MonitorDaemon.h"

#include "DQMServices/Core/interface/MonitorElement.h"
#include "FWCore/ParameterSet/interface/InputTag.h"

class L1Scalers: public edm::EDAnalyzer
{
public:
  /// Constructors
  L1Scalers(const edm::ParameterSet& ps);
  
  /// Destructor
  virtual ~L1Scalers() {};
  
  /// BeginJob
  void beginJob(const edm::EventSetup& c);

//   /// Endjob
//   void endJob(void);
  
  /// BeginRun
  void beginRun(const edm::Run& run, const edm::EventSetup& c);

  /// EndRun
  void endRun(const edm::Run& run, const edm::EventSetup& c);

  
//   /// Begin LumiBlock
//   void beginLuminosityBlock(const edm::LuminosityBlock& lumiSeg, 
//                             const edm::EventSetup& c) ;

  /// End LumiBlock
  /// DQM Client Diagnostic should be performed here
  void endLuminosityBlock(const edm::LuminosityBlock& lumiSeg, 
                          const edm::EventSetup& c);

  void analyze(const edm::Event& e, const edm::EventSetup& c) ;


private:
  DaqMonitorBEInterface * dbe_;
  edm::InputTag triggerScalersSource_;
  edm::InputTag triggerRatesSource_;
  edm::InputTag lumiScalersSource_;
  bool verbose_, monitorDaemon_;
  int nev_; // Number of events processed
  const L1TriggerScalers *previousTrig;


  MonitorElement * orbitNum;
  MonitorElement * trigNum;
  MonitorElement * eventNum;
  MonitorElement * phyL1Acc;
  MonitorElement * phyL1AccRaw;
  MonitorElement * randL1Acc;
  MonitorElement * techTrig;
  MonitorElement * numberResets;
  MonitorElement * deadTime;
  MonitorElement * lostTriggers;

  MonitorElement * trigNumRate;
  MonitorElement * eventNumRate;
  MonitorElement * phyL1AccRate;
  MonitorElement * phyL1AccRawRate;
  MonitorElement * randL1AccRate;
  MonitorElement * techTrigRate;
  MonitorElement * orbitNumRate;
  MonitorElement * numberResetsRate;
  MonitorElement * deadTimePercent;
  MonitorElement * lostTriggersPercent;
  

  MonitorElement *  instLumi;
  MonitorElement *  instLumiErr; 
  MonitorElement *  instLumiQlty; 
  MonitorElement *  instEtLumi; 
  MonitorElement *  instEtLumiErr; 
  MonitorElement *  instEtLumiQlty; 
  MonitorElement *  sectionNum; 
  MonitorElement *  startOrbit; 
  MonitorElement *  numOrbits; 

};

#endif // L1Scalers_H
