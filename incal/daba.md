---
title: "DaBa: Handling Datenbasen"
layout: single
permalink: incal/daba
author_profile: false
sidebar:
  nav: incal
toc: true  
---

## Handling Kursdaten

- 15.03.24: Es wird weiterhin PsExa.ps1 (statt Run.ps1) verwendet, weil es hier keine einzulesenden Eingabedaten gibt.

Was  | Wie
---- | -------------
Update von Kursdaten: | PsExa.ps1 'Hdl,Wiso,Kurse' -q DaBa\\Hdl\\Kurse\\Kurse BT
Update von Kursdaten-Testvariante | PsExa.ps1 'Hdl,Wiso,KurseTst' '-q -debS 11' DaBa\\Hdl\\Kurse\\KurseTst BT



````text
24.05.21: Aufgaben zu SQL-Tabellen
Eingabe zu -Exa: Wiso,ex0,ex1,...
Wiso: Aufruf von RmIoMgr::ExWiso(), ex0: Datenbasis, ex1: Definiert Funktion, 
+ eventuell weitere Eingaben abhängig von Funktion

---------------------------------------------------------------------------------
Aus ...\Work\DaBa\Wiso\Wiso.ps1:
Eingabe oder Update von Kursen,...

.\Wiso 'Wiso,TeWi,Kurse' TeWi
.\Wiso 'Wiso,Wiso,Kurse' Kurse

.\Wiso 'Wiso,TeWi,Ifo' IfoTeWi
.\Wiso 'Wiso,TeWi,EDir' DirTeWi
.\Wiso 'Wiso,TeWi,BtSc' BtScTeWi
.\Wiso 'Wiso,TeWi,DayeLo' DayeLoTeWi

.\Wiso 'Wiso,Wiso,Ifo' IfoWiso
.\Wiso 'Wiso,Wiso,EDir' DirWiso
.\Wiso 'Wiso,Wiso,BtSc' BtScWiso
.\Wiso 'Wiso,Wiso,DelIfoTbl' DelIfoTblWiso   <-- Eingabe auf c:\Wiso\Ifo.txt !!!!
.\Wiso 'Wiso,Wiso,DayeLo' DayeLoWiso
---------------------------------------------------------------------------------
Misc 'Hdl,TeWi,Del,BtSc,kXxTest' '-debS 11 -q' DaBa\Hdl\Del\TeWi   <-- Als Test

Misc 'Hdl,Wiso,Del,EDir,ComFo' '-debS 11 -q' DaBa\Hdl\Del\WisoDirComFo
Misc 'Hdl,Wiso,Del,EDir,DiBaFo' '-debS 11 -q' DaBa\Hdl\Del\WisoEDirDiBaFo
Misc 'Hdl,Wiso,Del,BtSc,kComFo' '-debS 11 -q' DaBa\Hdl\Del\WisoBtSc_kComFo
Misc 'Hdl,Wiso,Del,BtSc,kDiBaFo' '-debS 11 -q' DaBa\Hdl\Del\WisoBtSc_kDiBaFo
Misc 'Hdl,Wiso,Del,BtSc,kCoDiFo' '-debS 11 -q' DaBa\Hdl\Del\WisoBtSc_kCoDiFo

28.05.21: Bem.: In Wiso Börse werden die Files c:\\Wiso\\EDir.txt und 
c:\\Wiso\\BtSc.txt erzeugt, deren jeweils erster Zeileneintrag (z.B. DiBaFo oder 
kComFo) die eigentliche Aktion definiert.

Misc 'Hdl,TeWi,BtSc' '-debS 11 -q' DaBa\Hdl\BtSc\TeWi              <-- Als Test
Misc 'Hdl,Wiso,EDir' '-debS 11 -q' DaBa\Hdl\EDir\Wiso_DiBaFo
Misc 'Hdl,Wiso,BtSc' '-debS 11 -q' DaBa\Hdl\BtSc\Wiso_kComFo
Misc 'Hdl,Wiso,BtSc' '-debS 11 -q' DaBa\Hdl\BtSc\Wiso_kDiBaFo
Misc 'Hdl,Wiso,BtSc' '-debS 11 -q' DaBa\Hdl\BtSc\Wiso_kCoDiFo
````
