---
layout: single
title: LogBmBp
permalink: thems/bm-bp
sidebar:
  nav: thems
toc: true 
---

31.01.24: Protokoll zur "Rückabwicklung" der Verwendung von BmLib in BpLib, RtLib und RtM.

- 'Bm::Ba::Db(' ersetzt durch 'Bp::Bb::Db('
- In .../RtLib/src/RtMf erfolgt die "Rückabwicklung" durch das Ersetzen von 
  - Bp::SqlMgr* sqlMgr=Bp::SqlMgr::GetPtr(); durch
  - BpSqlMgr* sqlMgr=BpSqlMgr::GetPtr();
- In .../BpLib/src/BpMultMgr in MultMgr::InitMgr() ebenfalls Verwendung von 
  - 'BpSqlMgr* sqlMgr=BpSqlMgr::GetPtr();'
- In .../RtLib/src/RtIoMgr in IoMgr::ExHdl() ebenfalls Verwendung von 
  - 'BpSqlMgr* sqlMgr=BpSqlMgr::GetPtr();'
- BpSy muss noch angesehen werden!!!
- In BpQuote.cxx
 - In QuoteMgr::QuoteMgr(...): 'Bm::SqlMgr::GetPtr()->GetWpIfo(fBase,"Code",fCode,fWpIfo);' ersetzt durch
 'BpSqlMgr::GetPtr()->GetWpIfo(fBase,"Code",fCode,fWpIfo);'
 - In QuoteMgr::InitDaye(): 'Bm::SqlMgr* sqlMgr=Bm::SqlMgr::GetPtr();'  ersetzt durch
 'BpSqlMgr* sqlMgr=BpSqlMgr::GetPtr();' und 'sqlMgr->TblRange(fBC,fDayeFi,fBdxLa,fDayeLa);' durch 
 'sqlMgr->TableRange(fBC,fDayeFi,fBdxLa,fDayeLa);' + weitere Wiederbelebungen älterer Varianten in
 Bp.h, Bp.cxx,  BpQuote.h, BpQuote.cxx
 - Für QuoteMgr::ReadQuotes() gibt es eine auskommentierte Version, in der es kein Bm::... gibt:
 Es treten aber Fehler auf, die inzwischen (01.02.24) behoben sind. Dazu wurde viel "alter" Code aus v0.21 
 reaktiviert.
- 01.02.24: Bisheriger Test:
 - ````PS C:\Users\User\BsTd\Work\Irv\Rt> PsExa.ps1 '' '-debS 11' Irv\Rt\Release -BT````
 - auf + vor Wiso klicken
 - auf + vor Aktien/DAX klicken
 - Doppelklick auf DAX
 - File > Exit
 - In File .../Release.txt nach Vorkommen von 'Bm::' suchen (und beseitigen) 
- ```` PS C:\Users\User\BsTd\Work\Ik\Macd\Ppo\V1Tt> PsExa 'IkTt,Ppo,V1' '-dS 11' Ik\Macd\Ppo\V1Tt\IkPpoV1 -BT ````:
Ergebnis enthält kein 'Bm::'
- ````PS C:\Users\User\BsTd\Work\Sy\Rdm\Sys> PsInt 'Sy\SyRdm,S0' '-dS 1101' Sy\Rdm\Sys\SyRdmS0 -BT````:
Ergebnis enthält kein 'Bm::'
- 02.02.24: BpLib, RtLib, RtM compiliert ohne BmLib. In BpSqlMgr müssen WriteSgl() und WriteTot() überarbeitet
werden.
