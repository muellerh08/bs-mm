---
layout: single
title: Ursprüngliches ReadmeBp
permalink: /docs/readme-bp
sidebar:
  nav: doc_nav
toc: true 

---
<!-- {: .no_toc }
<details open markdown="block">
  <summary>
    Table of contents
  </summary>
  {: .text-delta }
- TOC
{:toc}
</details> -->

<!-- \section BsTd99 Ursprüngliches ReadmeBp -->
# Ursprüngliches ReadmeBp

Hier folgt die ursprüngliche Readme-Datei, in der in chronologischer Reihenfolge die
unterschiedlichsten Probleme behandelt wurden:
````
- 15.01.09: 
    Den Inhalt einer shared library kan man sich anschauen z.B fuer libRt.so via
\n     nm -Dg ./libRt.so | awk '$2 ~ /T/ { print $3; }' | c++filt > & libRt.txt 
\n  Oder auch mit dumpbin.exe aus Visual Studio! 
- 26.01.09: Ich hatte die Idee von TBrowser ausgehend das GUI für Rt zu "bauen".
	  Das scheitert daran, dass ich erst einmal keinerlei
	  Zusammenhang herstellen kann zwischen dem "Aussehen" und den
	  Funktionen von TBrowser und dem entsprechenden C++ Code. Auch die
	  Rolle der Klasse (ABC-abstract base class) TBrowserImp verstehe ich
	  ueberhaupt nicht!
\n  Etwas besser koennte es mit TTreeViewer aussehen. Hier scheint mir
	  der Code etwas verstaendlicher zu sein. Frage: GUI fuer Rt von
	  TTreeViewer ableiten, oder nur als Vorbild nehmen? Zunaechst sollte
	  ich wohl erst einmal die Funktionen von TTreeViewer einigermassen
	  verstehen.
- 28.01.09: Ich verstehe nicht, unter welchen Bedingungen eine Class Object in
	  die Liste gROOT->GetListOfClasses aufgenommen wird. RtSqlPlugin ist
	  entweder ueberhaupt nicht vorhanden, oder gleich 2 mal, wenn ich
	  gROOT->AddClass(this->Class()); 
	  in den Constructor schreibe. Und selbst dann erhalte ich einen
	  anderen Pointer als wenn ich GetPointer() verwende.
	  Die Verwendung des Pointers aus
	  (RtSqlPlugin*)(gROOT->GetListOfClasses()->FindObject("RtSqlPlugin"))
	  fuehrt dann auch zu Segmentation violation.
- 12.02.09: Talib ist 2* installiert weil es Schwierigkeiten gibt mit der
	  normalen Installation über yast
	  1. mit yast (-I/usr/include/ta-lib, /usr/lib/libta_lib.so)
	  2. Mit "downgeloadeten" tar file ~/Install/tar/ta-lib
	     (-I/usr/local/include/ta-lib, /usr/local/lib/libta_lib.so)
	     Der Suchpfad /usr/local/lib steht in /etc/ld.so.conf
    
	  Ich habe heftige Veraenderungen in ta_defs.h vorgenommen im Directory 
    ~/Install/tar/ta-lib/include. Dort sind viele
	  #define's. Speziell   
		#define ENUM_BEGIN(w) typedef enum {
  		#define ENUM_DEFINE(x,y) x
		#define ENUM_END(w) } TA_##w;
	  habe ich dann weiter unten ersetzt - eigentlich genau mit dem was
	  sie bedeuten sollten. Andernfalls wurde immer ein "unerwartetes Ende"
	  des Files ta_defs.h "beklagt". Keine Ahnung warum? 
	  So geht es jedenfalls erst einmal.
	  Die zweite Version mit "make uninstall" beseitigt. Lediglich die
	  include's werden von ~/Install/tar/ta-lib/include genommen.
    
- 18.02.09: Der Umgang mit Indikatoren kann sicherlich weitgehend aus Qtstalker
	  uebernommen werden. Es erweist sich aber als recht
	  muehsam. Vielleicht ist es ja einfacher, mit Makros zu arbeiten
	  (aehnlich wie in GeniusTrader).
- 23.02.09: Schwierigkeiten mit TGNumberEntry. Vielleicht helfen Erlaeuterungen
	  zu TGCompositeFrame::AddFrame() weiter:
	  Add frame to the composite frame using the specified layout hints.
	  If no hints are specified default hints 
	  TGLayoutHints(kLHintsNormal,0,0,0,0) will be used. Most of the time,
	  however, you will want to provide specific hints. User specified 
	  hints can be reused many times and need to be destroyed by the
	  user. The added frames cannot not be added to different composite
	  frames but still need to be deleted by the user.
- 27.02.09: Bei Aenderungen in RtBar kam es wieder einmal zu seltsamen
	  Abstuerzen, z.T. auch bei Mausbewegungen im Chartfenster. Erst das
	  Auskommentieren allen Codes, der mit den Tooltipps zusammenhaengt
	  (in RtBar und RtPoly) fuehrte wieder zu stabilen
	  Verhaeltnissen). Zur Zeit gibt es also keine Tooltipps.
- 28.02.09:
\n	Error: *** Datamember RtTaLib::fHandle: no size indication!
\n	Error: *** Datamember RtTaLib::fHandle: pointer to fundamental type
	(need manual intervention)
\n Das hatte ich schon einmal. Kann mich aber nicht mehr an die Ursache 
	erinnern.???????????????
\n Hat offenbar etwas mit CINT zu tun mit //! hinter der Deklaration ist
	die Sache behoben, wenn die Variable nicht "persistent" gemacht werden
	muss.
- 09.03.09: Mit make stimmt etwas nicht.
	  Bsp.: Aenderung in RtIndic.h: Funktion AddGraph gestrichen.
	  Diese Funktion wird aber in RtTaLib.cxx benutzt. Eine
	  Fehlerausschrift kommt erst nach make clean.
	  ==> Unbedingt klaeren!!!!!!!!!!!!!!!!!!!!!!!!!
	  Ich hatte schon mehrmals seltsame Abstuerze, die ich mir nicht
	  erklaeren konnte. Vielleicht ist das ja die Ursache?
- 18.03.09: Problem geloest!!!
- 29.03.09: Eine falsche Deklaration
  
	  fBuySell=new Int_t(fLength); statt
	  fBuySell=new Int_t[fLength];
  
	  hat mich sehr viel Zeit gekostet. Es wurde kein syntaktischer Fehler
	  angezeigt. Es gab aber Fehler, die offenbar mit der
	  Speicherplatzbelegung zu tun hatten. In Zukunft TArrayI benutzen. Da
	  gibt es Hinweise bei Zugriffen ausserhalb der array Grenzen!
- 29.03.09: Virtual destructors: siehe
	  http://www.codersource.net/cpp_virtual_destructors.html
	  Bei einer von TNamed abgeleiteten Klasse braucht es offenbar keinen
	  virtuellen destructor, da TNamed einen solchen hat!
- 31.03.09: Bei GeniusTrader (GT) gibt es signals and systems, wobei die Signale
	  aus Indikatoren abgeleitet werden, waehrend ein System Vorschlaege
	  fuer buy und sell Order liefert. Mir ist nicht klar, warum diese
	  Zwischenstufe zwischen Signalen und einem vollstaendigem
	  Handelssystem eingefuehrt wurde. Ein Handelssystem umfasst dann
	  zusaetzlich noch MoneyManagement, Closestrategien, Tradefilters
	  usw. Da Signale beliebig kompliziert aus beliebig vielen Indikatoren
	  aufgebaut werden koennen, werde ich mir diese Zwischenstufe erst
	  einmal sparen und unter "system" ein vollstaendiges Handelssystem
	  verstehen. 
- 17.05.09: Besonderheiten bei Fonds:
\n    Kassa	= Rücknahmepreis
\n	  Open	= Zwischengewinn
\n	  High	= Ausgabepreis
\n  In der Spalte "Kurs" finden Sie den Nettopreis des Wertpapiers, also
    den Preis abzüglich Zwischengewinn:

	  Im Beispiel:
    Kassa â€“ Open = Rücknahmepreis (Netto) â€“ Zwischengewinn =
	  Nettopreis   88,30 â‚¬ - 0,14 â‚¬ = 88,16 â‚¬

    siehe Börse 2009 online-Hilfe im Kapitel, bzw. Bedienbuch S. 318
	  Depotauswertungen
	     Steuerberechnung
	        Exkurs: Zwischengewinne bei Fonds und Auswirkungen auf die
	  		Auswertungen 

	 In Wiso Boerse werden die Aktien in ein file quotes.txt und die Fonds
	 in ein file fonds.txt ausgegeben. In quotes.txt steht der Schlusskurs
	 auf close, waehrend in fonds.txt der Kassa-Kurs auf close steht. Bei
	 den Fonds ist es eher unwahrscheinlich, dass ich mich fuer
	 open=Zwischengewinn und high=Ausgabepreis interessiere. Zur Zeit
	 befinden sich aber in der Datenbank RtWiso.quotes viele Fonds, bei
	 denen der Kassa-Kurs fehlt. Eine Liste dieser Fonds gibt es in
	 ~/Projekte/RT/Work/DB/fondsinfo.txt. Nach Korrektur wird dort
	 gestrichen! 
-11.07.09: In Analogie zu root hatte ich irgendwann angefangen, Listen
	  anzulegen fuer sogenannte Singletons (Klassen, fuer die im Programm
	  nur ein objekt erzeugt wird). Bei Bedarf wurden dann die Objekte aus
	  den Listen geholt. Im Moment scheint mir das ziemlich umstaendlich
	  zu sein (allein schon vom Hinschreiben). Wahrscheinlich sollte ich
	  doch wieder dazu ueberzugehen, solche Objekte als Parameter zu
	  uebergeben. Das sollte auch die "Zugehoerigkeiten" deutlicher
	  machen! 
- 19.07.09: Der Versuch, das Qt-Interface zu installieren ist wieder einmal
	  gescheitert. Es sieht aber so aus, als wuerde es nur mit Qt4 gehen.
	  Mit QTDIR=/usr/lib/qt4 gibt es aber beim Uebersetzen von Rt ganz
	  merkwuerdige Fehler. Deshalb habe ich im Makefile gesetzt
	  QTDIR=/usr/lib/qt3, d.h. die Umgebungsvariable steht auf Qt4, intern
	  in Rt aber auf Qt3!!!
- 25.08.09: Ich hatte in der Zwischenzeit versucht, Rt auf M09 unter Vista zu
	  installieren. Bin aber vorlaeufig gescheitert. Im Verlauf dieser
	  Aktion habe ich zahlreiche Aenderungen vorgenommen an Programmen,
	  die ich glÃ¼cklicherweise in M09:/Users/muellerh/RT/README.txt
	  geschrieben habe. Hier jetzt der Versuch, beide Varianten wieder in
	  Einklang zu bringen. Liste der "bearbeiteten" Programme:
\n	  indic/RtTaLib
\n	  filt/RtTrend
\n	  port/RtPfBase
\n    port/RtPortfolio: Auf M09 RtPfTable raus, hier unverändert.
- 26.08.09: Umstellung auf Subversion.
	  RT/Rt090826 ist die Version,die als Startversion in Subversion
	  verwendet wird. Mit dem symbolischen link Rt -> trunk kann sogar das
	  Makefile unverÃ¤ndert bleiben.
- 19.10.09: Inzwischen gibt es eine sehr ausführliche Anleitung zum Installieren
	  des Qt Interfaces QtRoot  
	  http://root.bnl.gov/QtRoot/How2Install4Unix.html
	  MIt dem Script INSTALL_QTROOT.sh wurde (mit minimalen Ã„nderungen)
	  alles installiert.
    Wenn ich aber die gegenwärtige Version mit
    
	  # GUI specific settings.
	  Gui.Backend:   qt
	  Gui.Factory:     qtgui
    
	  als "Qt-based ROOT Application" anwende (spielt aber offenbar bei
	  der Übersetzung noch keine Rolle), dann gibt es einige
	  Merkwürdigkeiten:
	  1. Die erzeugten Tabellen "zittern" und sind damit unlesbar.
	  2. Keine tooltips im Chart.
	  3. Bei den Kontrollausdrucken in ~/RT/Work/RtTest/Interactive 
	     werden aus Real-Zahlen Integer.
	  4. Bei den Ausdrucken in ~/RT/Work/SysTest/MacdF erscheint anstelle
       des Dezimalpunktes ein Komma (aber nicht überall!).
	  
	  Was tun??????????????????????????
- 01.11.09: In RtQuote funktionieren Tooltipps nur in der"root" Variante, bei
	  der  "Qt" Variante kommen Fehlerausschriften und die Tooltipps sind
	  nicht da. Aber TQtWidget genauer ansehen. Dort scheint es Hinweise
	  zu geben. Auch ~/Install/QtRoot/qtRoot/qtExamples/CustomCanvasMenu
	  sollte zur Klärung beitragen!!!

- 06.11.09: Tooltips funktionieren jetzt auch in Qt Variante. Es fehlte connect();
          [04.08.10: Offenbar ist
          connect(CF21,SIGNAL(
                    RootEventProcessed(TObject *, unsigned int, TCanvas *)),this,
                  SLOT(CanvasEvent(TObject *, unsigned int, TCanvas *)));
          in  RqCF2::InitCF2() gemeint, wobei
          TQtWidget* CF21=new TQtWidget(fCW,"CF21");]

	  In der Qt-Variante liefert TString(string).Atof() einen integer????
	  Dagegen scheint QString(string).toDouble() zu funktionieren. Das
    habe ich in RtDepotMgr::Init() geändert. Es gibt bestimmt noch mehr
	  Stellen. 
- 25.12.09: In RtBackTest::Single() wurde nur ein einzelnes Wertpapier
	  betrachtet. Als "Koordinatensystem" wurden einfach die Tage genommen
	  an denen Kurse vorhanden sind. Mit dem Ãœbergang zur gleichzeitigen
	  Betrachtung mehrerer Wertpapiere funktioniert das nicht mehr, weil
	  sich die Anzahl der vorhandenen Kurse durchaus unterscheiden
	  kann. Deshalb werden als weiteres Koordinatensystem die Wochentage
	  (alle Tage auÃŸer Sonnabend und Sonntag) eingefÃ¼hrt, das fÃ¼r alle
	  Darstellungen verwendet wird. SÃ¤mtliche Berechnungen fÃ¼r ein
	  bestimmtes Wertpapier werden aber nach wie vor im internen
	  Koordinatensystem der vorhandenen Kurse ausgefÃ¼hrt. Bei der
	  Darstellung und beim Vergleich mehrerer Werpapiere wird Ã¼ber das mit
	  einem bestimmten internen Index (ind) verknÃ¼pfte Datum
	  (z.B. daye=20070612) in das System der Wochentage (indW)
	  umgerechnet.
- 14.02.10: Ich habe wieder einmal versucht, die alte Idee umzusetzen, mit
          1. und 2. Ableitung die richtigen Zeitpunkte fuer Ein-, bzw. Ausstieg zu
          bestimmen. Das scheitert daran, dass es mir nicht gelingt, eine hinreichend
          geglaettete Kurve zu erzeugen, von der man dann die Ableitungen berechnen
          koennte (siehe RtMap und RtMomP).

- 25.07.10: Inzwischen ist openSUSE 11.3 installiert (mit großen
	  Schwierigkeiten). Mein Versuch, von root Version 5.24 auf 5.26
	  umzusteigen ist auch (zunächst?) gescheitert. Es gibt
	  Schwierigkeiten mit mysql und der Qt Unterstützung, siehe
	  ~/Install/Root/ReadmeHM .

- 27.07.10: Bis auf make qtcint funktioniert so weit alles. Wichtig ist das Setzen von
          $GUI=qt, wenn Qt Programme genutzt werden sollen (siehe
          root/etc/system.rootrc, # GUI specific settings.)

          Bei Eingabe von   trade.Append("|CS:BreakEven 1 .1");
          in .../RT/Work/Systest/DaxSma1.C wird wieder aus .1 eine 0 in der
          Qt Variante (vgl. 06.11.09), also in RtBreakEven TString(string).Atof()
          ersetzen durch QString(string).toDouble() ersetzen. Diese Sache wird
          wohl noch oft auftreten!
- 02.08.10: In .../indic/src/RtIndQuo.cxx wieder 0.1 in 0 umgewandelt.
          Behoben durch Ersetzen von
          "TString sIn=...; Double_t val=sIn.Atof();"
          durch "val=QString(sIn.Data()).toDouble();"
- 03.08.10: Eine Suche nach Atof liefert eine lange Liste dieser potentiellen
          Fehlerquelle, die ich gern aus "Suchergebnisse" (Qt-Creator) hierher
          kopiert hÃ¤tte. Das
          ging aber nicht. Am einfachsten ist das Problem wahrscheinlich durch eine
          von TString abgeleitete Klasse RtString zu lÃ¶sen, in der Atof Ã¼berschrieben
          wird. In folgenden Funktionen auf RtString "umgestellt":
          RtATR, RtBreakEven, RtFixed, RtKeepUp, RtTrend, RtFSI, RtIndQuo, RtMaP,
          RtMacdN, RtMomP, RtTalib, RtFixedPc, RtFixedRisk, RtFixedSum, RtQuote,
          RtSqlCfgMgr, RtSqlMgr, RtSqlWiMgr, RtYahoo.

- 05.08.10: Wenn $GUI=qt gesetzt ist, um RqTable im Backtest benutzen zu kÃ¶nnen, dann
          funktionieren in RtChartPage die tooltips nicht mehr. Wahrscheinlich kann
          das nur behoben werden, indem in einer neuen Klasse RqChartPage
          (abgeleitet von QtMainWindow) ein TQtWidget zum zentralen Fenster gemacht
          wird. RtChartPage wird in RtVarSys erzeugt, RtMultMgr hat ein Array von
          RtChartPage's. Eine solche Ã„nderung fÃ¼hrt also zu weitreichenden
          Konsequenzen.
          WÃ¤re eine Trennung in zwei Programme, Root- und Qt-Applikation, sinnvoll???

- 06.08.10: Der Aufwand ist sehr hoch, deshalb zunÃ¤chst Ã¼berprÃ¼fen, ob die Root-
          Applikation nicht doch dazu gebracht werden kann, mit $GUI=native und
          $GUI=qt "gleich" zu arbeiten.

          Die Tooltips in RtStocktree werden mit "native" nahe des Items, mit "qt"
          aber in der Bildmitte dargestellt. Da ich den Tooltiptext lediglich mit
          TGListTree::SetToolTipItem(item,tip.Data()); eingebe, habe ich keinerlei
          EinfluÃŸ auf den Ort der Darstellung. Damit dürfte es ein "Root-internes"
          Problem sein.

          RtQuote ist eigentlich von RtBox abgeleitet. Aber selbst bei Ableitung
          von TBox verschwinden mit "qt" die Tooltips.

- 08.08.10: Es gelingt mir nicht, die Rq* Klassen, die alle irgendwie von QObject
          abgeleitet sind, in die "Dictionary-Erstellung" einzubeziehen, obwohl das
          laut Manual möglich sein soll. Sobald include QObject im Headerfile
          erscheint, stürzt alles ab.

- 09.08.10: Beim gegenwärtigen Stand der Installation ist es auch nicht möglich,
          ein beliebiges include Q.* (außer QGlobal, hier wird Q_UNUSED()
          benutzt) in einem Rt* Headerfile unterzubringen. Damit kann ich
          RtMultMgr nicht zusammen mit RqChartPage (oder einer entsprechenden QList,
          die Pointer zu RqChartPage-Objekten enthält) benutzen (siehe auch 05.08.10).
          Im Endeffekt läuft das darauf hinaus, dass ich generell auf ROOT-based
          Qt-Applikation umstellen muÃŸ. Scripting in Qt4 ist völlig anders (kein C++,
          wie in ROOT). Falls nicht so eine Art Wrapper (z.B. eine Klasse
          RqMultMgr, die ein Member RtMultMgr hat) funktioniert, mÃ¼sste alles neu
          geschrieben werden!!!

- 12.08.10: Mein erster Eindruck, dass eine ROOT-based Qt-Applikation die ROOT-Klassen
          gut "vertrÃ¤gt", endet an der Stelle, wo es um die Generierung von Signalen
          geht. Sobald ich in ein RqChartPage Objekt mit der linken Maus-Taste
          klicke, kommt es meist zu einem Crash. Meine Vermutung ist nun, dass die
          in RtH2D dabei erzeugten Signale die Ursache sein kÃ¶nnten. Um das
          abzustellen muÃŸ aber das gesamte "Zoom GeschÃ¤ft" umgestellt werden. Statt
          der Signale aus RtH2D sollte RtChartPage::EventInfo() benutzt werden.
          Gleichzeitig sollte es sinnvoll sein, aus RtSystem+RtVarSys einen
          RtChartMgr zu machen. Dort kÃ¶nnten dann alle benÃ¶tigten Arrays
          gespeichert werden!

- 13.08.10: Umstellung des "Zoom GeschÃ¤fts" Ã¤ndert nichts an den AbstÃ¼rzen in
          RqChartPage beim Mausklick! Andererseits gibt es diese AbstÃ¼rze in
          RqMainWindow+RqCF2 nicht. Was ist da der Unterschied????

- 09.01.11: Nach einigen "Irrungen und Wirrungen" (Umstellung auf Qt-Composer,
   Nutzung von Visual Studio 2010 auf Windows, Nutzung verschiedener Versions-
   Kontroll Systeme wie Mercury und Git) glaube ich jetzt eine Version zu
   haben, die auf Linux und Windows funktionieren sollte und mit Qt-Composer
   "gehaendelt" wird. 
   Heute Versuch eines "Neuanfanges":
   Auf Linux in /home/muellerh/MyPro/RtG/Rt
   unter Windows in /Users/muellerh/...
   Bei den neuen Pfadbezeichnungen habe ich auf eine Mischung von Gross- und
   Kleinbuchstaben geachtet, weil auf der externen Platte mit dem Repository,
   Pfade mit ausschliesslich Grossbuchstaben in Kleinbuchstaben umgewandelt
   worden sind. Ich habe keine Ahnung, wieso!

   Das neue Repository unter Linux mit 
   svnadmin create /media/HDDRIVE2GO/Repos/RtG/Rt
   erstellt und dann mit
   svn import Rt file:///media/HDDRIVE2GO/Repos/RtG/Rt/trunk -m "Initial
   import" 
   die Daten importiert. Die weitere Bearbeitung erfolgt mit kdesvn.
   
- 12.03.11: Bis hierher bezieht sich alles auf das Projekt Rt (basiert auf Root).
   Im folgenden wird Projekt Tq (basiert auf Qt4) kommentiert.
   
   Beim Versuch, die Info Tabelle aus MySQL mit QSqlTableModel darzustellen, bin ich 
   zunaechst gescheitert. Sobald die Tabelle mit select() gefuellt werden soll, gibt
   es einen Assertion failure. Wenn ich das "ausserhalb" in einem extra Programm mache
   tritt dieser Fehler nicht auf (siehe ./QtExamples/sql/tablemodel).
   Es scheint an der Tabelle Info zu liegen, andere Tabellen mit Kursdaten 
   funktionieren.
- 13.03.11: Die Info-Daten werden in ein QSqlTableModel eingelesen und koennen von da aus
   im Programm verwendet werden. Das Verwenden eines QTableView's zum Darstellen geht
   immer noch nicht.
   Beim Versuch das GSI-Root-Interface einzubinden kommt sofort nach Programmstart die
   Meldung: "QWidget: Must construct a QApplication before a QPaintDevice"
   Das hatte ich schon beim Projekt Rg. Dort ging es dann, wenn das QtMainWindow 
   nicht dynamisch, sondern statisch gelinkt wurde.
   Das scheint hier aber nicht zu funktionieren, der Fehler bleibt! 

- 14.03.11: Auch wenn TQRootCanvas in main erzeugt wird kommt die obige Fehlermeldung!
   Da muss ich also auch die ganze Zeichnerei in Qt machen!
   
- 17.03.11: Es gibt ein Projekt QWT, das auf Qt aufbauend offenbar für Zeichnungen
   verwendet werden kann. Dort wird qmake verwendet und könnte als "Vorbild" dienen
   für meine *.pro Files. Ich nehme an, dassŸ das doch einfacher ist als mit
   Visual  Studio. Da mit qmake auch die *.vcxproj Files hergestellt werden
   können, kann Visual Studio immer noch verwendet werden.
   Für QWT wird qtAddLibrary verwendet aus
   $QTDIR/mkspecs/features/qt_functions.prf.
   Dort wird offenbar dafür gesorgt, dass die Debug-Libraries ein zusätzliches
   "d" am Ende ihres Namens erhalten. Damit können dann Debug und Release
   Versionen mit "CONFIG += debug_and_release" gleichzeitig erstellt werden.
   Ich weißŸ aber nicht, ob das auch mit der Applikation geht?

- 29.03.11: Eine Darstellung von Candlesticks ist in QWT in der Version 6.0
   offenbar nicht vorgesehen und ist auch nicht ganz einfach zu realisieren,
   weil die Datenstruktur ziemlich festgelegt ist. Es hat aber eine Diskussion
   darüber stattgefunden, siehe
   "http://sourceforge.net/mailarchive/forum.php?thread_name=
   78f82c3e0903191242m52567cb8ja2de6a273ed4b8be%40mail.gmail.com&forum_name=
   qwt-interest".
   Außerdem habe ich ein Projekt, "http://code.google.com/p/candelabro/"
   gefunden, in dem Candlesticks offenbar implementiert sind. Sie sind dort
   direkt in QWT eingebunden, allerdings in eine ältere Version. Ich will
   versuchen, die relevanten Teile als entsprechend abgeleitete Klassen in
   TqBase zu implementieren. Das Verständnis der QWT-Struktur ist nicht ganz
   einfach. Einige (mühsam gesuchte) Details sollen hier festgehalten werden
   für eventuelle spätere Nutzung.
   Ausgangspunkt ist die Klasse:
   class QwtPlotPrice: public QwtPlotSeriesItem<QwtPriceMove>
   Sie ist zu sehen in Analogie zu
   class QwtPlotCurve: public QwtPlotSeriesItem<QPointF>
   class QwtPlotIntervalCurve: public QwtPlotSeriesItem<QwtIntervalSample>
   class QwtPlotHistogram: public QwtPlotSeriesItem<QwtIntervalSample>
   class QwtPlotSpectroCurve: public QwtPlotSeriesItem<QwtPoint3D>
   die alle eine Serie von Daten unterschiedlicher Art darstellen können.

   In "class QwtPlotItem: public QwtLegendItemManager" gibt es ein
   enum RttiValues{}, das bei Candelabro einfach um Rtti_PlotPrice ergänzt
   wurde. Ich müsste das in einer von QwtPlotItem abgeleiteten Klasse tun,
   habe aber keine Ahnung, was ich da mit dem enum in dieser Klasse tun soll
   (obwohl so etwas vorgesehen ist  Rtti_PlotUserItem = 1000).

   Vergleich:
                       QwtPlotPrice <--> QwtPlotIntervalCurve
    QwtPlotSeriesItem<QwtPriceMove> <--> QwtPlotSeriesItem<QwtIntervalSample>
    (qwtC_price_move)  QwtPriceMove <--> QwtIntervalSample (qwt_series_data)
(qwtC_series_data)QwtPriceMoveSeriesData <--> QwtIntervalSeriesData
                                                        (qwt_series_data)
    
- 30.03.11: Um die Analogie zu  QwtPlotIntervalCurve deutlicher zu machen, wird
   auch die Namensgebung verändert, indem Interval durch Price ersetzt wird:
   
           QwtPrice (qwtC_price.h) <--> QwtInterval (qwt_interval.h)
                 QwtPlotPriceCurve <--> QwtPlotIntervalCurve
         (qwtC_plot_pricecurve.h)            (qwt_plot_intervalcurve.h)
 (qwtC_series_data.h) QwtPriceSample <--> QwtIntervalSample (qwt_series_data.h)
 (qwtC_series_data.h) QwtPriceSeriesData <--> QwtIntervalSeriesData
                                                         (qwt_series_data.h)
    QwtPlotSeriesItem<QwtPriceSample> <--> QwtPlotSeriesItem<QwtIntervalSample>
   (qwtC_plot_pricecurve.h)                       (qwt_plot_intervalcurve.h)
   
   Es ist ein Alptraum. Eine verhältnismäßig bescheidene Änderung erfordert
   ein Hinabtauchen in viele Stufen von Vererbungen, die für den Laien nicht
   immer sehr verständlich sind. Wahrscheinlich einfacher, wenn ich mir eine
   vereinfachte Variante von QWT herstelle!

- 31.03.11: Ein letzter Versuch. Der Autor selbst meint zu einer ähnlichen 
   Anfrage: "I recommend to implement a new type
   of plot item. It is not too much code ( of course you have to know, what
   QPainter is ) and should be much easier, than misusing QwtPlotCurve.
   Maybe it helps to look at the histogram example: it is an example how to
   implement a new plot item."  Also werde ich auch damit vergleichen. Zuletzt 
   hatte ich so meine Schwierigkeiten mit dem Keyword "const". So erfolgt das
   Übergeben der Daten durch "void setSamples(const QVector<...>&". In den 
   Klammern steht dann beim Histogramm-Beispiel QwtIntervalSample und bei mir
   QwtPriceSample. Das bedeutet, dass der entsprechende Vektor von 
   darzustellenen Werten nicht verändert wird durchs Plotten.
   Auch die Datenabfrage in QwtIntervalSample erfolgt in der "const" Form:
   
   //! \return Lower limit of the interval
   inline double QwtInterval::minValue() const
   {
      return d_minValue;
   }
   
   Sicherlich muß ich das in QwtPrice genauso machen!

- 30.03.11-gegen 11:45Uhr: Es funktioniert!!!
   Allerdings nur schwarz-weiß. Und selbst ein simples Ändern von Farben wird
   wegen der const's zur Horroraufgabe. Da QwtPlotPriceCurve ein const-Objekt 
   ist, kann es nur einmalig über den Konstruktor mit Werten belegt werden.

- 22.04.11: Das Zeichnen von Candles geht inzwischen auch in Farbe.
   Jetzt scheitere ich aber daran, daß ich keine zwei QwtPlot-Objekte mit
   gleich breiter canvas() herstellen kann. Die unterschiedlich breite Be-
   schriftung der y-Achse verhindert das. Und ich finde keine (einfache)
   Möglichkeit, das zu ändern. Es ist zum Verzweifeln mit dem QWT!

- 23.04.11: Aber auch dafür scheint es eine Lösung zu geben: siehe QWT,examples,
   plotmatrix, void PlotMatrix::alignVAxes(int col, int axis) und hier:
   http://www.qtcentre.org/threads/9347-Qwt-Using-QwtPlotPicker-on-multiple-plots

- 10.07.11: Ich verstehe nicht, warum einige Programme wie TqQuoteMgr, TqTalib,
   TqCF2,... immer wieder kompiliert werden, obwohl keinerlei Änderungen 
   vorgenommen wurden. Mein Verdacht ist, dass das mit den 4 shared Libraries
   zusammenhängt, in die das Projekt aufgespalten ist. Sicherlich wäre es 
   sinnvoller gewesen, alles in eine Library zu packen. Eine Umstellung zum
   jetzigen Zeitpunkt scheint aber ziemlich umständlich zu sein. So müssen u.A.
   in den Klassendefinitionen: 
   class TQBASE_EXPO TqDate : public QDate
   die Zusätze wie TQBASE_EXPO geändert werden. 
   Was die *.pro/pri Files betrifft, so ist ein gewisser Anfang gemacht 
   (siehe $TQDIR/TqLib). 
   Es handelt sich immer um die gleichen Files, die (grundlos) recompiliert 
   werden: TqQuoteMgr, TqTaLib, TqCF2 und TqChartPage. Irgendwelche 
   Besonderheiten kann ich dort nicht entdecken!
   
- 16.07.11: Es gibt jetzt eine Variante mit nur einer shared Library. Das ging   
   im Grunde genommen relativ einfach durch das Definieren von TARGET=TqLib in 
   TqBib1.pri. Aber das Recompilieren der erwähnten 4 Files bleibt! Jetzt ist
   die Frage, ob ich bei meinen 4 Bibliotheken bleibe, oder ob ich doch die
   (einfachere) Variante mit 1 Bibliothek nehme???

- 09.08.11: Über das "Meta-System" von Qt4 können die Bestandteile eines enums
   als QString verfügbar gemacht werden. Ein Beispiel ist in TqPos realisiert.

- 14.08.11: Neues Verzeichnis .../Tq/TqTest. Dort soll alles "gesammelt" werden,
   das zum Testen dient (und eigentlich, bzw. später als Script geschrieben
   werden sollte). Dazu gehören TqIndicTest, TqSys, TqScan.

- 15.09.11: Neues Verzeichnis .../Tq/TqScript. Hier wollte ich zunächst das
   einfachste Beispiel aus Qt Script Examples, Hello Script, als Testfall
   benutzen. Ich hatte zunächst die Vorstellung, das Hauptprogramm aus diesem
   Beispiel in meinem Tq-Hauptprogramm mit unterzubringen. Das ist aber
   allerhand Code, da offenbar jede C++ Funktion/Klasse irgendwie präpariert
   werden muß, um sie von den Scripts aus zu verwenden. Da ich aber
   voraussichtlich ziemlich viele Scripts benötigen werde, muß das ganz sicher
   anders "organisiert" werden. Es kann ja wohl auch nicht sein, dass jeder
   Script mit einem eigenen Hauptprogramm "ausgestattet" wird???

- 05.12.11: Im Zusammenhang mit der Generierung künstlicher Kursdaten bin ich
   (wieder einmal) auf das Interface-Problem Qt4-ROOT gestoßen. Das
   GSI-Interface habe ich irgendwie zum Laufen gebracht, indem ich das
   offenbar für Qt3 gebaute Interface auf Qt4 umgestrickt habe. Es gibt dafür
   im Qt4 ein Tool, qt3to4. Nachdem ich dann auch noch alle ClassDef's und
   ClassImp's herausgeworfen hatte, ging es mit root_v5.30.04. Dazu gibt es
   ein Verzeichnis .../Tq/TqQtGSI als eigenständiges Projekt, das aber auch
   in Tq eingebunden werden kann. Nachdem ich allerdings auf root_v5.32.00
   umgestellt hatte, ging es schon nicht mehr. Bei dem Aufruf
   TQApplication a("uno",&argc, argv); gab es einen Fehler:
   "read access violation". Vorläufig muß ich also bei root_v5.30.04 bleiben!
	 
- 03.01.12: Bei "root" wird inzwischen mit cmake gearbeitet. Damit kann ich root
   unter Windows selbst installieren. Als Option kann auch das Interface mit Qt4
   installiert werden. Allerdings muß in einem zusätzlichen Schritt auch noch
   qtcint erzeugt werden. Das ist in der Dokumentation in .../root/cint/cint 
   beschrieben, ist mir aber noch nicht gelungen. Ich habe also immer noch kein
   "richtiges" Interface, da .../Tq/TqQtGSI offenbar auch nicht alles macht, wie
   ich es mir vorgestellt habe. Ich versuche jetzt erst einmal, in einem Projekt
   "Bp" das root-Projekt "Rt" und das Qt4-Projekt "Tq" paralell zu betreiben und
   so weit wie möglich zu vereinheitlichen. In den Klassen, die keine Signale 
   verwenden und deshalb nicht zwingend von TObject, bzw. QObject abgeleitet
   werden müssen, bietet sich die Verwendung einer gemeinsamen Basis-Klasse an, in
   die alles gepackt wird, was unabhängig von root und Qt4 formuliert werden kann.
   In den anderen Fällen kommt vielleicht eine weitere Klasse in Frage, die dann
   von beiden Varianten verwendet werden kann. Alles "Gemeinsame" soll also in "Bp"
   gepackt werden, um "Rt" und "Tq" auf das unbedingt Nötige zu reduzieren. Mal
   sehen, wie weit ich damit komme.
	
- 04.01.12: Ich hatte Schwierigkeiten, aus einem QString einen const char* zu 
   machen. Funktioniert hat schließlich die Umwandlung von QString in string via
   string = QString.toLocal8Bit().constData(); 
   Die Funktion std::string QString::toStdString () const geht nicht. Im 
   Manual steht: 
   This operator is only available if Qt is configured with STL 
   compatibility enabled.
   Das müßte ich dann bei der nächsten Installation beachten!

- 02.07.12: RtCF2, RtChartFrame, RtChartPage, RtChartMgr, RtQuote aus Programm 
   entfernt.
		
- 08.08.12: Bisher hatte ich die Backtest-Ergebnisse in Xml-Dateien geschrieben, die
	dann zum Darstellen im Browser benutzt wurden. Damit ist aber keine Sortierung 
	möglich. Deshalb Umstellung auf Sql Server 2012. 
	Benutzung von sqlcmd:
  
	Von den vielen beschriebenen Verbindungsmöglichkeiten funktioniert nur
	        'sqlcmd -S lpc:M09\SQLEXPRESS'
	Das Abarbeiten einer *.sql Datei erfolgt mit
          'sqlcmd -S lpc:M09\SQLEXPRESS -i Datei.sql'
	z.B.: 'sqlcmd -S lpc:M09\SQLEXPRESS -i C:\Users\muellerh\BP\SqlServer\HeidiSQL\InfoY.sql'
	
*****************************************************************************

- 19.11.12: Neuer Rechner Win8-12 mit Betriebssystem Windows 8 und 64bit.
  "Strategie" für Installation: 
    1. Funktionierende Variante auf M09 zunächst nicht verändern.
    2. Auf Win8-12 zunächst den "Rt-Teil" weglassen.
    3. Als Datenbank nur den SQL Server von Mikrosoft verwenden, also MySql entfernen.
    4. Es muß VS2010 verwendet werden, da die installierte Variante Qt5 damit übersetzt ist.

- 20.11.12: Es muß Qt4 verwendet werden, da es ansonsten Schwierigkeiten mit QWT gibt.
	Es kommen jetzt die Fehler, die mit der "Nichtinstallation" von MySql zusammenhängen.
	Dazu werde ich die Originalversion der betroffenen Methoden in einen Ordner 
	...muellerh/BPR kopieren, bevor ich die entsprechenden Änderungen vornehme.
  
- 21.11.12: Das erzeugte Tqd.exe kann erst einmal nicht gestartet werden. Da ich eine übersetzte
  Version von Qt4 installiert hatte, war ich der Meinung, dass keine weitere Konfiguration
  nötig sei. 
  
  Jetzt habe ich in einem Qt4.8.3 Command Prompt Fenster
  im Ordner c:\MyProgs\Qt\4.8.3 den Befehl .\configure abgesetzt.
  Da hat sich noch einmal eine Menge getan. Am Ende kam die Meldung:
  Qt is now configured for building. Just run nmake.
  To reconfigure, run nmake confclean and configure.
  Das sieht nach einer "Neuinstallation" aus. Verstehen tu ich das nicht!
  
  Bei der Verwendung von shared_ptr<...> gibt es auch Schwierigkeiten. 
  Die Definition befindet sich in '#include <memory>'. 
  rootcint scheint das aber nicht zu finden. Wenn ich den entsprechenden Pfad,
  "c:/Program Files/Microsoft Visual Studio 10.0/VC/include", in der CMakeLists.txt eingebe, kommt 
  beim Kompilieren an vielen Stellen der Fehler:
  'C:\Program Files (x86)\MSBuild\Microsoft.Cpp\v4.0\Microsoft.CppCommon.targets(151,5): 
  error MSB6006: "cmd.exe" wurde mit dem Code -1073741819 beendet.'
  Zu diesem Fehler finde ich nichts im Internet.
  Ohne diesem Pfad kommt:
  7>  Generating G__RtLib.cxx, G__RtLib.h
  8>  Tqd.exe.vcxproj -> C:\Users\muellerh\BpH\BpBuild\bin\Debug\Tqd.exe
  7>CUSTOMBUILD : error : no such template shared_ptr<BpQuoteMgr> C:/Users/muellerh/BP/Bp/BpLib/inc\BpMultMgr.h(22)
  7>CUSTOMBUILD : error : no such template shared_ptr<BpCloseMgr> C:/Users/muellerh/BP/Bp/BpLib/inc\BpMultMgr.h(23)
  7>CUSTOMBUILD : warning : Error occurred during reading source files
  7>CUSTOMBUILD : warning : Error occurred during dictionary source generation
  7>  !!!Removing G__RtLib.cxx G__RtLib.h !!!
  7>CUSTOMBUILD : error : C:\root\\bin\rootcint: error loading headers...
  
  Auf M09 hatte ich offenbar die BOOST-Bibliotheken installiert und einen Link dorthin
  gemacht. ???

- 22.11.12: Es bleibt dabei, dass Tqd.exe nicht gestartet werden kann. 
  Es bleibt also nichts anderes übrig, als das ganze Programm wieder
  einmal "scheíbchenweise" neu aufzubauen. Dabei beabsichtige ich auch, 
  die Zahl der Teilprojekte zu reduzieren.
  
- 23.11.12: Tqd.exe kann nur gestartet werden, wenn fast alles auskommentiert
  ist. Den aktuellen Stand habe ich jetzt in Bpcmake121123 fixiert und
  versuche in BP nur mit VS10 zu arbeiten.

- 24.11.12:	Es bleibt bei einem "SideBySide" Fehler. Nützlich hierbei waren
  muellerh\bin\depends.exe mit den darin gegebenen Hinweisen.
  cmake findet nicht immer die Microsoft Kompiler, auf keinen Fall darf der
  Ordner "CMakeFiles" im Build-Ordner gelöscht werden!

  Wenn ich eine statische Bibliothek erzeuge, dann scheint erst mal das
  Programm zu starten.

- 25.11.12: Um arbeiten zu können werden also statische Bibliotheken verwendet.
  - Verbindung zu SqlServer wird in c:\\Qt\\4.8.3\\src\\plugins\\sqldrivers\\odbc
    "gemacht".
  10Uhr: Mit der statischen BpLib ging es, aber nachdem ich TqBib dazugenommen
  hatte war der SideBySide Fehler wieder da. Auch CCleaner brachte keine
  Besserung.
  Bei der Fehlersuche sind, neben dem Dependency Walker (muellerh\bin\depends.exe),
  folgende Dinge nützlich:
  1. Das Anwendungsereignisprotokoll wird über 
  Start->Einstellungen->Systemsteuerung->Verwaltung->Ereignisanzeige
  gefunden.
  2. sxstrace:
  
	  2.1 Open up a command prompt (as administrator) and run the following
    command c:\windows\system32\sxstrace Trace -logfile:sxstrace.log
    2.2. Open up a new command window and run your command, in this case for
       me it was simply curl.exe.
    2.3. Once the error has been thrown, go back to first command prompt and
     press any key to stop the tracing.
    2.4. Now issue the following command
    c:\windows\system32\sxstrace Parse -logfile:sxstrace.log 
                                        -outfile:sxstraceInfo.txt
    The results of the trace will be in readable format within the generated
    text file.
  
- 02.12.12: Ursache für das ganze Schlamassel war die schlampige Installation der
	ta-lib Bibliotheken. Es müssen die "richtigen" Versionen angegeben werden
	für Release, Debug, ...
	Um den Fehler zu finden, wollte ich "scheibchenweise" installieren. Das ging
	erst einmal nicht, da ich in BpQuoteMgr auch noch das Management der 
	Indikatoren und der Signale hineingepackt hatte. Deshalb habe ich wieder einen
	BpIndMgr und einen BpSigMgr für die Indikatoren und Signale eingeführt.

- 07.12.12: Es scheint soweit wieder alles zu funktionieren. Es gibt aber 
	Schwierigkeiten bei der Verwendung von smart pointern, sobald rootcint
	ins Spiel kommt. Diese sind im Header <memory> in 
	 c:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\include
  
	definiert. Sobald ich diesen Pfad zu den include_directories hinzufüge,
	kommt eine Flut von Fehlern beim Erstellen des Dictionary. Ohne diesem
	Pfad kommen Fehler wie z.B. 
	CUSTOMBUILD : error : no such template shared_ptr<BpCloseMgr> 
	C:/Users/muellerh/BP/Bp/BpLib/inc\BpMultMgr.h(23), wobei 
	typedef shared_ptr<BpCloseMgr> closeMgr_ptr; in BpMultMgr.h definiert ist.
	Zur Zeit umgehe ich diesen Fehler, indem ich BpMultMgr nicht mehr als
	Basisklasse für RtMultMgr verwende, sondern nur noch als ein Member. Damit
	vermeide ich das #include "BpMultMgr.h" in RtMultMgr.h, und damit 
	verschwindet BpMultMgr aus dem Aufruf von rootcint.
	Das ist natürlich keine Lösung für den Fall, wenn smart pointer im "Rt"-Teil
	verwendet werden sollten. Vielleicht sollte dann die Verwendung der
	BOOST-Bibliothek in Betracht gezogen werden, anstelle der "Microsoft-eigenen"
	smart pointer????

- 19.12.12: Nachdem der Rechner zwischenzeitlich wegen eines defekten RAM-Riegels
	den Geist aufgegeben hatte, geht jetzt so weit wieder alles. Dabei schaut es 
	so aus, als würde ich mit VS2012 Programme verwenden, die mit VS2010 kompiliert
	sind. Das trifft auf jeden Fall für c:\root zu. Bezüglich Qt4 hatte ich am
	21.11.12 geschrieben, dass ich im Ordner c:\MyProgs\Qt\4.8.3 .\configure und 
	nmake gemacht habe, was ja einer "Neuinstallation" entsprechen würde, wobei 
	nicht einmal klar ist, welcher Compiler dabei verwendet wurde, da vermutlich
	zu diesem Teitpunkt VS2010 und VS2012 vorhanden waren. Den
	Ordner gibt es aber nicht mehr, und in dem vorhandenen c:\Qt\4.8.3 ist alles
	vom 22.11.12. Vermutlich habe ich das ursprüngliche Installationsfile noch
	einmal angewendet und nichts verändert. Also ist es offenbar die VS2010-er Version.
	Gleiches gilt für QWT. Dort gibt es im Makefile eine Zeile
	Makefile: qwt.pro  ..\Qt\4.8.3\mkspecs\win32-msvc2010\qmake.conf 

- 08.01.13: Die Eröffnung einer Position ist nicht besonders übersichtlich geregelt.
  Zuletzt habe ich das enum Bp::EWpType, das eigentlich nur den Typ des 
	Wertpapieres festlegen soll, mit den Werten kCfdHL, kCfdLmt und kCfdMkt erweitert.
	Damit wurde die Eröffnung einer Position in Relation zu den Kursen vom Signaltag
	gesteuert. Wahrscheinlich dürfte es sinnvoller sein, in Analogie zu BpClose,
	eine Klasse BpOpen einzuführen, mit der dann die Varianten einer 
	Positionseröffnung gesteuert werden können. Hier sind dann der Variationsvielfalt
	nahezu keine Grenzen mehr gesetzt.
  
- 25.02.13: Bis zum 30.03.12 wurde die Zusammensetzung der setN's aus der entsprechenden
Tabelle der Datenbank genommen. Danach wurde alles aus den
Info-Tabellen genommen, die beim Programmstart gelesen werden. Dabei wurde eine
Map 'map<string,list<string>*>* BpSqlMgr::fSetMap' angelegt, die verwendet wurde,
um im Hauptfenster die Wertpapiere in einer Baum-Struktur anzuordnen. Vor ein paar 
Tagen kam ich dann zu der "Erkenntnis", daß die Idee, alles in die Info-Tabelle zu 
schreiben, offenbar doch nicht die optimale Lösung ist. 
Wenn z.B. ein Fond sowohl in ComDia, als auch in FlaFo eingetragen werden soll, dann
muessten beide unter SetN stehen (eventuell mit Komma getrennt). Hier waere dann
die separate SetN-Tabelle die einfachere Loesung, da dann ein Wertpapier unter 
beliebig vielen Sets erscheinen koennte.
Bisher war ein Set durch ein Schlüsselwort und eine Liste von Wertpapier-Codes
gegeben. Als Erweiterung soll das Schlüsselwort (bei Bedarf) durch eine 
Ordnerstruktur ersetzt werden. Diese Ordnerstruktur kann in das QTreeWidget
übertragen werden nach dem Beispiel aus
http://stackoverflow.com/questions/10348801/populate-qtreewidget-with-hierarchic-structure-from-absolute-filepaths

- 11.04.13: Die Aufnahme neuer Wertpapiere aus Wiso Börse in die Datenbank von BP
erfordert folgende Schritte: siehe Ergänzung vom 02.01.15.
1. "Sammeln" der Wertpapiere in einem Ordner in WisoBörse.
2. Mit Kursdaten-Export-Konfiguration "InfoW" die Daten für die Info-Tabelle
   in c:\Wiso\Ifo\infow.txt bereitstellen. Der Eintrag "SetN" sollte durch eine 
	 Bezeichnung ersetzt werden, die eventuell bei der Suche in der Info-Tabelle
	 hilfreich sein kann, sonst aber keine Bedeutung mehr hat. Diese Daten können
	 mit Tq.exe über das "File"-Menü eingelesen werden.
3. Damit die Wertpapiere über den DeskTree betrachtet werden können, muß die
   Tabelle dbo.IfoSet in der Wiso Datenbank belegt werden. Das erfolgt mit der
	 Kursdaten-Export-Konfiguration "IfoSet", mit der c:\Wiso\Ifo\ifoset.txt
	 erzeugt wird. Der Text "IfoSet" muß durch die Bezeichnung ersetzt werden, unter
	 der die Wertpapiere erscheinen sollen. Hier ist eine Baumstruktur möglich mit
	 Schrägstrichen "/". Diese Daten werden wieder mit Tq.exe über das "File"-Menü 
	 eingelesen.
4. Für den Export der eigentlichen Daten wird die Kursdaten-Export-Konfiguration 
   "Export" benutzt.
5. Wenn die Wertpapiere für das Backtesting und/oder das Scannen verwendet werden
   sollen, dann muß die Tabelle dbo.IfoBtSc in der Datenbasis BT1 belegt werden.
	 Dazu wird die Kursdaten-Export-Konfiguration "IfoBtSc" verwendet, wobei der
	 Text "IfoBtSc" durch eine Bezeichnung ersetzt wird, die mit dem Buchstaben "k"
	 beginnen muß. Das Einlesen der Datei c:\Wiso\Ifo\IfoBtSc.txt erfolgt wieder 
	 mit Tq.exe über das "File"-Menü.

- 27.05.13: Das Löschen einzelner Einträge erfolgt am besten über das Server Mangement 
   Studio in den verschiedenen Tabellen mittels Menupunkt "Alle Zeilen  bearbeiten".
	 Insgesamt gesehen ist das ganze Verfahren aber recht umständlich, weil mehrere
	 Tabellen geändert werden müssen. Die Alternative wäre, alles in der Info-Tabelle
	 unterzubringen. Da wäre aber die Auswertung komplizierter.

- 10.06.13: Bei der Darstellung der Zeitachse habe ich bisher ein Koordinatensystem
   verwendet, das alle Wochentage (einschließlich eventueller Feiertage) enthielt.
	 Das ist sinnvoll für den Fall, dass mehrerer Kursverläufe in einem Chart
	 dargestellt werden sollen, da bei verschiedenen Wertpapieren an unterschiedlichen
	 Tagen Kurse fehlen können. Meist wird aber nur ein einzelnes Wertpapier
	 betrachtet. Hier sollte die Aneinanderreihung der vorhandenen Kurse die
	 einfachere Variante sein. Bei Indikatoren wie IndMt oder IndZz entfallen dann
	 auch die Knicke in den eigentlich geraden Linien, die durch Fehltage hervorgerufen
	 werden. Das sollte zumindest als Variante ins Programm eingebaut werden.
	 20.09.13: Das ist inzwischen relisiert durch Einbau eines Zeit-Mangers BpZeitMgr.

- 20.09.13: Auf dem neuen Rechner Win8-12 hatte ich lange Zeit nur mit der Release 
		Variante gerechnet. Die Debug Variante läßt sich nicht starten und stürzt
		sofort ab. Die Anwendung von ~/bin/depends.exe weist auf einen sidebyside
		Fehler hin. Wenn ich den Anweisungen von 
		http://www.winvistaside.de/forum/index.php?showtopic=3575
		folge bekomme ich als Fehlermeldung:
		FEHLER: Der Verweis "Microsoft.VC80.DebugCRT,processorArchitecture="x86",
		publicKeyToken="1fc8b3b9a1e18e3b",type="win32",version="8.0.50727.762"" 
		kann nicht aufgelöst werden.
		Es fehlt also eine "Runtime", die offenbar von hier
		http://www.microsoft.com/en-us/download/details.aspx?id=5638
		heruntergeladen werden könnte. Dort steht:
		"Mit Microsoft Visual C++ 2005 SP1 Redistributable Package (x86) werden 
		Laufzeitkomponenten von Visual C++-Bibliotheken installiert, die erforderlich 
		sind, um Anwendungen, die in Visual C++ entwickelt wurden, auf einem Computer 
		auszuführen, auf dem Visual C++ 2005 nicht installiert ist."
		Nun steht die Frage, ob ich so alte Software auf den Rechner laden muß?
		Welche Debug-Bibliothek braucht denn das Zeugs?
		Qt und QWT habe ich (wahrscheinlich?) auf dem Rechner "hergestellt". Da sollte
		also alles i.O. sein.
		ROOT gibt es als Release- und Debug-Variante. Mit dem Installer wird alles in
		c:\root gebracht. Ich habe die Debug-Variante in c:\rootd umbenannt. Dort kann 
		ich dann root.exe nur benutzen, wenn in der Eingabeaufforderung vorher 
		thisroot.bat ausgeführt wurde. Danach ist auch %ROOTSYS%=c:\rootd. Wahrscheinlich 
		muß cmake(-gui) von eben einer solchen Eingabeaufforderung aus ausgeführt werden!

		Ursache für den Fehler war das Einbinden der Debug-Bibliotheken von TaLib.
		Nach http://ta-lib.org/d_api/d_api.html sind die Release-Versionen mit 'cdr' 
		und die Debug-Versionen mit 'cdd' bezeichnet. Und diese 'cdd'-Versionen sind 
		offenbar die Fehler-Ursache. Mit den 'cdr' Versionen funktioniert alles. In dem
		...\BP\CMakeList.txt-File wird lediglich %ROOTSYS% entweder auf c:\root oder
		c:\rootd gesetzt. Es muß also auch kein thisroot.bat ausgeführt werden!

- 25.09.13: Zu meinem Erstaunen habe ich gemerkt, dass in die Debug-Variante am
   Ende doch die Release-Versionen der ROOT-Bibliotheken eingebunden waren (zu
	 sehen im Output-Fenster 'Ctrl-Alt O' von VS2012). Erst nachdem ich nur die Debug-
	 Variante von ROOT installiert hatte, sind die Debug-Bibliotheken auch eingebunden.

- 26.09.13: Und es gibt jede Menge Fehler, die mir teilweise völlig unverständlich
   sind, die aber wahrscheinlich darauf zurückzuführen sind, dass ROOT mit VS2010
   "gebaut" ist, ich aber VS 2012 verwende. 
	 In BpLib werden jetzt überhaupt keine Dictionaries mehr hergestellt. Deshalb
	 können BpMultMgr nicht mehr an RtMultMgr, und BpTradeMgr nicht mehr an RtTradeMgr
	 vererbt werden. Aus "Is a" Relationen sind also "Has a" Relationen geworden. Das
	 geht aber auch.
	 Die Debug-Variante für BP scheint aber auch mit der Release-Variante von ROOT zu
	 funktionieren.
	 Bei einem neuen Projekt findet cmake(-gui) die Compiler nicht. Alle Hinweise aus
	 dem Internet (Eingabeaufforderung aus VS, bzw. vcvarsall.bat als Admin ausführen)
	 helfen da nicht. Als "Workaround" können die Files 
	 ..\Build\CMakeFiles\2.8.11.2\CMakeCXXCompiler.cmake und ...CMakeCCompiler.cmake
	 von einer funktionierenden Variante in das neue Build-Directory kopiert werden.
	 Dort sind die Compiler gesetzt, z.B.
   set(CMAKE_CXX_COMPILER "C:/Program Files (x86)/Microsoft Visual Studio 11.0/VC/bin/cl.exe")

- 09.10.13: Für die Suche nach den optimalen Parametern beim Backtesting scheint das
   Verfahren der Simulated Annealing geeignet. Allerdings gibt es Rechenzeiten von
	 über einem Tag für ein Portfolio aus ca. 70 Fonds. Das Verfahren aus der GSL
	 (Gnu Scientific Library) ist in ROOT integriert, es ist aber keine Eingabe
	 der Parameter möglich, es müssen die Default-Werte verwendet werden. Um daran 
	 etwas zu ändern, habe ich versucht, von 	GSLSimAnMinimizer und  GSLSimAnnealing
	 die Klassen RtSimAnMinimizer und RtSimAnnealing abzuleiten. Damit bin ich aber
	 gescheitert, weil es Programm-Abbrüche gibt, die ich nicht verstehe. 
	 Wahrscheinlich muß ich diese beiden Programme komplett übernehmen und neu 
	 kompilieren, wobei die (inzwischen installierte) GSL-Library verwendet werden
	 muß.

- 15.10.13: 
  1. Mit VS2012 kann sowohl Visual Studio 11.0 als auch Visual Studio 10.0
	verwendet werden. Da ROOT z.Zt. mit VS10 "hergestellt" ist, liefert auch nur
	VS10 in der Debug-Variante ein Programm, das auch gestartet werden kann. 
	Trotzdem funktionieren die Makros nicht, da z.B. 
	           RtMultMgr* multMgr=RtMultMgr::GetPtr()
  multMgr=1 liefert und damit keine gültige Adresse. Da ich nicht weiß, wie das
	zusammenhängt, muß ich also weiterhin mit der Release Variante von ROOT arbeiten.
	Also auch in die Debug-Variante von Rt.exe ist Release von ROOT eingebunden.

	2. CMake spinnt! Das geht damit los, dass die Kompiler nicht gefunden werden. 
	Dann waren nach einer Neukonfiguration mit cmake-gui plötzlich jede Menge 
	Details "verschwunden", obwohl die CMakeLists.txt unverändert waren. Als
	Workaround half nur die Verwendung des Verzeichnisses CMakeFiles von einer
	älteren funktionierenden Variante. Bei Weiterverwendung vom CMake darf der Cache
	keinesfalls mit cmake-gui gelöscht werden, weil dabei auch das Verzeichniss 
	CMakeFiles verschwindet. Notfalls also bestenfalls CMakeCache.txt von Hand
	löschen.

	3. Eigentlich brauche ich ja CMake überhaupt nicht, da ich ja nur mit VS arbeiten
	will. Ich weiß nur nicht, wie ich es loswerden kann. Z.B. taucht die "Herstellung"
	der Dictionaries mit rootcint in der IDE gar nicht auf, sondern nur in 
	RtLib.vcxproj. Auch die mit cmake erzeugten *.vcxproj Files sind offenbar
	unnötig kompliziert, da ich zu viel vom ROOT-Build übernommen habe. Das sollte
	ich in einem ersten Schritt vereinfachen.

- 03.12.14: Ich habe (wieder einmal) versucht, die memory leaks zu finden, die beim
  Parameterfit von Handelssystemen auftreten. Dazu habe ich den 
	Visual Leak Detector for Visual C++ 2008/2010/2012/2013
	(siehe http://vld.codeplex.com/documentation) und das 'Suchen von 
	Arbeitsspeicherverlusten mit der CRT-Bibliothek' 
	(siehe http://msdn.microsoft.com/de-de/library/x98tx3cf.aspx)
	versucht anzuwenden. In beiden Fällen ist es mir nicht gelungen, irgendeinen
	Bericht über eine eingebauten Fehler zu erhalten. Wahrscheinlich habe ich Fehler 
	beim Anwenden gemacht???!!!

- 02.01.15: Ergänzung zum 11.04.13: Aufnahme neuer Wertpapiere in die Datenbank.
  Es wird nur noch eine Informationstabelle 'afo.Ifo' verwendet. Mit der 
	Kursdaten-Export-Konfiguration "Ifo" werden die Daten für diese Tabelle
  in c:\Wiso\Ifo.txt bereitgestellt. Die Ifo-Tabelle hat eine Spalte 'EDir',
	die dem entsprechenden Ordner in Wiso Börse entsprechen sollte, und für die 
	Darstellung im Explorer-Fenster im RtMainFrame verwendet wird. Als weitere Spalte 
	gibt es 'BtSc', die analog behandelt wird und Zusammenstellungen von Wertpapieren 
	für Backtesting und Scannen enthält. Die Daten werden mittels der 
	Kursdaten-Export-Konfigurationen "Dir" und "BtSc" in c:\Wiso\Dir.txt und
	c:\Wiso\BtSc.txt abgelegt.
	Für den Export der eigentlichen Daten wird statt "Export" die Export-Konfiguration 
  "Kurse" benutzt, mit der die Daten in c:\Wiso\Kurse geschrieben werden.

- 20.01.15: Inzwischen will ich als Vereinfachung Qt nicht mehr verwenden. Damit ist
   auch die gesamte Struktur mit dem Bp-Bereich als Basis sowohl für den Tq- als
	 auch für den Rt-Bereich eigentlich überflüssig. Bisher wurden die reinen
	 Rechnungen in Bp ausgeführt, alles, was mit Zeichnungen und Signalen zu tun hat,
	 wurde in Tq und Rt verlagert. In Root ist eigentlich vorgesehen, dass sich die
	 Objekte "selbst zeichnen". Das geht aber mit der Bp,Tq,Rt-Struktur nicht, weil
	 dazu Rt-Objekte erzeugt werden müssten. Beispielsweise werden Positions- und
	 Transaktions-Objekt als BpPos- und BpTra-Objekte im Bp-Bereich erzeugt. Im Zuge
	 der Einführung von Positionsaufstockungen (Pyramidisierung) sollen die Ergebnisse
	 mittels RtPolyLine mit der Basis TPolyLine dargestellt werden. Am einfachsten
	 wäre es, die PolyLine-Objekte als Member in den Positions-Objekten zu haben.
	 Das erfordert erhebliche Änderungen in Bp/RtTradeMgr. So richtig weiß ich noch
	 nicht, wie ein "gleitender" Umbau erfolgen könnte.

- 23.02.15: Beschluß: Tq aus dem Programm entfernen. Die gestrige Variante 
   "vorsichtshalber" aufheben als BPmitTq150222. In ...BP\CMakeList.txt werden
	 die beiden Befehle add_subdirectory(Tq/TqLib) und add_subdirectory(Tq/TqMain)
	 auskommentiert.
  
- 25.05.15: Umstellung auf C++/Clr, um die Microsoft-Bibliotheken nutzen zu können.
  Beim Kompilieren der "native" C++-Klassen mit /clr funktioniert aber bindexplib
	nicht mehr, wo die *.def Files für den Ex/Import hergestellt werden. Die 
	andere Möglichkeit, mit den  __declspec-Definitionen im Quelltext ist kaum
	praktikabel, da dann auch die mit rootcint hergestellten Files zusätzlich
	entsprechend geändert werden müssten. Deshalb werden die Wrapper-Klassen für
	den Aufruf von managed Code aus native Code ins Rt-Hauptprogramm-Projekt 
	geschrieben, weil dann der Ex/Import entfällt.

- 04.09.15: Für die Verwendung von managed Code in native Code sind Wrapper 
  erforderlich, die in einer eigenen shared Library stehen sollten. Diese sollte
	dann in BpLib und RtLib eingebunden werden. Dazu ist aber das Export-Problem zu
	lösen, das eindeutig mit der /clr Option zusammenhängt und den folgenden Fehler
	liefert:
	BnLib.def : fatal error LNK1242: '?hypot@@$$J0YANNN@Z' is an invalid export symbol name
  Die Fehlerbeschreibung von Microsoft (siehe 
	https://msdn.microsoft.com/en-us/library/7stath7h%28v=vs.71%29.aspx )
	hilft nicht weiter: "An exported name contains an invalid character, such as a 
	period (.) character. Valid characters in an export name are anything allowed in 
	a C/C++ identifier plus @ and ?".
	An dem Namen selbst kann ich nichts finden, allerdings steht die Bezeichnung
	'hypot' in den nicht beanstandeten *.def-Files immer nur einzeln auf einer
	Zeile und niemals in einer solchen Kombination mit anderen Zeichen. 
	Wenn dieses Problem gelöst wäre, dann könnte wahrscheinlich das gesamte Programm
	mit der /clr-Option übersetzt werden, und dann könnte managed und native Code
	offenbar beliebig "gemischt" werden. Dazu müsste entweder bindexplib geändert
	werden oder CMake 3.4 abgewartet werden. Dort soll es dann eine Option zum 
	Herstellen der *.def-Files aus den *.obj Files geben (, wobei der Code dazu vom
	Root-Team stammen soll).

- 05.09.15: Mit der Development-Version 'cmake-3.3.20150904-gbb946-win32-x86.exe'
  und 'set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)' kommen exakt die gleichen Fehler,
	wenn die Option /clr verwendet wird!!!

- 16.09.15: Das Problem mit dem Export habe ich inzwischen gelöst. Allerdings muss
  dazu der Quelltext der Programme geändert werden, da auf bindexplib.exe verzichtet
	wird. Die Symboltabelle (zu erhalten mit DUMPBIN) einer *.obj-Datei wird sehr viel
	größer, wenn mit der Option /clr übersetzt wird. Da war mir dann die Beschäftigung
	mit dem bindexplib.cxx Programm doch zu aufwendig. Also doch die Verwendung von
	__cdecl... im Quelltext. Mittels eines Präprozessor Makros läßt sich erreichen,
	dass beim Precompile-Schritt der Dictionary-Erstellung die "einfache" 
	Klassen-Vereinbarung und dann beim Compilieren die mit __cdecl... erweiterte
	"sichtbar" ist. Trotzdem ist es mir nicht gelungen, mein gesamtes Programm mit
	/clr zu übersetzen. So gibt es Schwierigkeiten mit der Ta-Lib Bibliothek, und
	auch die in Bp.h/cxx enthaltenen Klassen führen zu Abstürzen beim Programmende.
	Das hängt offenbar mit den statischen Größen in dieser Datei zusammen und das ist
	hier (http://stackoverflow.com/questions/11835748/0xc0020001-the-string-binding-is-invalid-only-occurring-in-wpf)
	diskutiert. Um möglichst wenig ändern zu müssen werde ich erst einmal mit 4
	Bibliotheken (BmLib, BpLib, RtLib und RmLib) arbeiten, wobei die mit dem "m" mit
	/crt übersetzt werden. Bei "Bedarf" werden einzelne Klassen in den 
	c++/cli-Bereich übernommen.

- 22.09.15: Bp.h/cxx ist inzwischen in BmLib. Die Ursache für die Abstürze beim 
  Programmende war die statische Definition einer BpStringVec-Klasse in BpIkMgr.
	Warum ohne /clr eine normale Beendigung erfolgte, mit /clr aber ein Absturz, ist
	mir allerdings völlig unklar.

- 09.02.16: Inzwischen bin ich wieder davon abgekommen, "soviel wie möglich" mit
  /clr zu übersetzen, weil es an vielen Stellen "seltsames" Verhalten gibt. BpLibN 
	und RtLibN sind reine C++ Bibliotheken, während RmLib managed Code enthält. Hier
	geht es vor allem um die Nutzung von DataGridView.

	Der Rechner Win8-12 ist Ende Januar kaputt gegangen, und es war eine 
	Neuinstallation auf dem neuen Rechner Ac16 erforderlich. Dabei gab es doch einige
	Besonderheiten, die ich mir bei der Installation von Win8-12 leider nicht
	aufgeschrieben hatte, und die dann viel Zeit gekostet haben:

	- TSQLServer: Hier muss ein Plugin installiert werden. Das geschieht durch den
	 einmaligen Aufruf von 
	 root_v5.34.34\Release\etc\plugins\TSQLServer\P050_TODBCServer.C vom
	 Command-Prompt des eigenen Programms RtN aus. Eventuell auch von root.exe aus.
	 Ich hatte beides gemacht und dann ging es irgendwann. Ich verstehe nicht, wie 
	 dieser Plugin-Mechanismus funktioniert, und wieso das mit einem einmaligen 
	 Aufruf getan ist. Ich habe jedenfalls keinerlei "Spuren" entdeckt, die dieser
	 Aufruf hinterlassen hat. Als Alternative könnte man eventuell den Inhalt von
   P050_TODBCServer.C (gPluginMgr->AddHandler(...); ...) direkt in BpSqlMgr 
	 aufzurufen, oder gleich die verwendeten Programme TODBCResult, TODBCRow, 
	 TODBCServer und (TODBCStatement) aus	root\sql\odbc (, wobei TODBCStatement nicht 
	 zu funktionieren scheint???) in BpLibN zu kopieren.

  -GSL-Library: Für die Version 1.8 gibt es eine Variante mit einem Solution File
	 libgsl.sln, das eine direkte Installation mittels Visual Studio erlaubt:
	 http://sourceforge.net/projects/gnuwin32/files/gsl/1.8/
   Dort gibt es auch eine Installationsanweisung 
	 gsl-1.8-src.zip\src\gsl\1.8\gsl-1.8\VC8\Readme_VC8.htm oder auch auf
	 http://www.quantcode.com/modules/smartfaq/faq.php?faqid=94
	 Das Übersetzen hat geklappt, bei der Installation auf C:\Prog\libgsl-1.8
	 musste ich manuell nachbessern, wobei das "Nachbessern" darin bestand,
	 dass ich alles von Win8-12 herüberkopiert habe. 
   - 16.02.16: Und das war offenbar die Ursache dafür, dass ich die Debug 
	 Varianten meiner Programme nicht starten konnte. Erst bei Verwendung
	 der auf Ac16 kompilierten Bibliotheken gab es keine Schwierigkeiten mehr. 
	 Die neueste Version 2.1 mit Solution File habe ich nicht gefunden.

  -ta-lib: Hier gibt es ebenfalls ein Solution-File und die Bibliotheken
	 sollten neu erstellt werden. Dabei werden aber nur statische Bibliotheken 
	 hergestellt, so dass hier kein Angaben im Pfad erforderlich sind.

  -Boost-Library: 
	 1. Verwendung von Installationsdatei: boost_1_60_0-msvc-14.0-64.exe
	   Das Ergebnis steht in E:\\Prog\\boost_1_60_0
   2. Verwendung von boost_1_60_0.zip: Hier muss installiert werden wie
	   in der Datei index.html beschrieben. Das Ergebnis befindet sich in 
		 C:\\Prog\\boost_1_60_0. Am Ende der Installation kommt der Hinweis:
		 The Boost C++ Libraries were successfully built!
		 The following directory should be added to compiler include paths:
		 C:\\Prog\\boost_1_60_0"
		 The following directory should be added to linker library paths:
		 C:\\Prog\\boost_1_60_0\\stage\\lib"
   Ich habe beide Installationen ausprobiert, weil ich die Debug-Varianten
	 der Hauptprogramme BpN, RtN und RtM nicht starten kann. Mit den Release 
	 Varianten gibt es keinerlei Schwierigkeiten. Sicherlich ist die Variante am
	 besten, wo die Programme auf dem Rechner erzeugt werden, auf dem sie
	 auch verwendet werden. 
- 14.02.16:	Für die Systemwiederherstellung von Windows 10 gibt es sowohl eine CD
  als auch einen USB-Stick (SanDiskUltra USB 3.0 32GB).
- 16.02.16: Debug Variante funktioniert nicht mit Curl. Da ich das bisher kaum 
  benutzt habe, wird es vorläufig nicht mehr benutzt. Das betrifft lediglich
	die Klasse BpCurl und die Methode RtStockdialog::HandleHistory() und
	kann demzufolge bei Bedarf leicht rückgängig gemacht werden.
- 18.02.16: Die Verwendung von UnitTests funktionierte nur für die Release 
  Konfiguration. Es hat sich herausgestellt, dass das offenbar an der Verwendung
	von VisualLeakDetektor Version 2.5 lag. Mit der Version 2.4rc2 (die auf Win8-12 
	installiert war) trat das nicht auf. Damit wurde allerdings auch kein Memory
	Leak gefunden in der gleichen BsTd Version, bei der die VisualLeakDetektor 
	Version 2.5 massenweise Ausdrucke produzierte. Bei "Nichtverwendung" von 
	VisualLeakDetektor funktionieren die UnitTests sowohl in der Release als auch
	in der Debug Konfiguration. Da übrigens beim Installieren von VisualLeakDetektor
	der Speicherort der Bibliotheken in den System-Pfad geschrieben wird, genügt ein
	#include <vld.h> (z.B. in BpIoMgr und RtIoMgr), um VisualLeakDetektor zu benutzen. 
	Die	Umgebungsvariable 'LEAKDETDIR' und die Einträge in den CMake-Files sind
	offenbar überflüssig. 

	Auch ohne VisualLeakDetektor lassen sich die Debug Konfigurationen der Programme
	mit BpCurl nicht starten auf Ac16, auf Win8-12 funktioniert es. Auf Ac16 nur die 
	Release	Konfiguration: Also weiterhin erst einmal ohne BpCurl!

- 19.02.16: Die Unit-Tests in der Debug Konfigurationen funktionieren, wenn der 
  VisualLeakDetektor disabled wird via VLD = off in 
	C:\Program Files (x86)\Visual Leak Detector\vld.ini. vld.ini läßt sich aber nur 
	mit Administrator Privilegien ändern, z.B. mit Notepad++. Alternativ müssten die
	'#include <vld.h>' Einträge in Bp- und RtIoMgr auskommentiert werden.

	Ich habe immer noch das Problem, dass beim Fit mit BpHs der Speicherbedarf
	anwächst, ohne dass ich bisher ein Memory Leak gefunden habe.


- 04.03.16: Die andere Baustelle bei der Memory Leak Suche ist die sehr 
  unübersichtliche Berechnung der Minima in BpHs(). Wenn ich mir das Beispiel
	E:/Prog/Root/root_v5.34.34.source/root/math/mathmore/test/simanTSP.cxx
	ansehe, dann sollte es auch viel einfacher gehen. Dort wird lediglich eine 
	von GSLSimAnFunc abgeleitete Funktion f an ein GSLSimAnnealing-Objekt übergeben,
	um eine Minimierung mittels gsl_siman_solve durchzuführen. Dabei müssen zusammen
	mit f die Methoden wie Energy(), Distance(), Step(),... dem vorliegenden Problem
	angepasst werden. Damit kann alles weggelassen werden, was mit 
	ROOT::Math::Minimizer zusammenhängt. Damit dürften auch die Transformationen
	wegfallen, die für die Parameter mit limitierten Wertebereich durchgeführt 
	werden. Die Grenzen können sicherlich in die Methode Step() eingebaut werden.

- 12.03.16: Im Rahmen meiner "Umbauarbeiten" zur Minimierung habe ich mir erstmals
  die GSLSimAnParams angeschaut. Bisher hatte ich die Default Werte benutzt und
	lediglich mit t_min die Rechenzeit festgelegt. Wenn man sich aber die Boltzmann
	Verteilung bol=exp(-(new_E - E)/(params.k * T)) für den Fall new_E>=E anschaut,
	dann wird schnell klar, dass (mit params.k=1) sich die Temperatur T zumindest 
	nicht um Größenordnungen von der Energiedifferenz unterscheiden sollte. In
	dem meisten Fällen habe ich bisher für die "Energy" GuVPa benutzt, das Werte von
	100-1000 erreichen kann. Dementsprechend sind GuVPa-Differenzen in der 
	Größenordnung 10-100 zu erwarten. Dazu passt natürlich der Default-Wert der
	Anfangstemperatur von t_initial=0.002 überhaupt nicht. Die Boltzmann-Verteilung
	war praktisch immer =0, und somit gab es nie den Fall, dass ein lokales Minimum 
	wieder verlassen wurde. Andererseits gab es diese Schrittweitenvergrößerung in
	GSLSimAnMinimizer::Minimize() und die Parametertransformationen wegen der
	Parameterlimits. Damit wurde wahrscheinlich im gesamten Parameterraum nach dem
	Minimum gesucht, und die bisherigen Ergebnisse dürften nicht ganz abwegig sein.
	Wahrscheinlich bin ich mit einem Temperaturbereich von 100 ... 1 besser beraten,
	und mit mu > 1 (mit dem die "Abkühlung" entsprechend T /= mu gesteuert wird)
	könnte die Rechenzeit gesteuert werden.

- 21.12.16: Bei der Verwendung von Makros mit der Debug-Variante gibt es Abstürze, die
  mit der Release-Variante nicht passieren. Auch bei Rechnungen, bei denen Managed
  Code verwendet wird, können wahrscheinlich keine Macros verwendet werden. Deshalb
  war ich im Laufe des Jahres dazu übergegangen, alle Eingaben über Textdateien zu
  erledigen. Das ist aber bei weitem nicht so komfortabel, wie die Verwendung von
  Makros. Deshalb habe ich doch wieder begonnen, mit Makros zu arbeiten. Dazu müssen
  die entsprechenden Klassen aus der BpLib mittels des ClassDef()-Pragmas dem 
  Interpreter "bekannt" gemacht werden. Mit den managed Klassen aus der RmLib geht das
  wegen der \clr Option nicht.
- 31.07.17: Bisher habe ich versucht, das Pyramidisieren von Positionen in BpPyMgr zu
  regeln. Wahrscheinlich dürfte es einfacher sein, diese Betrachtungen in BpPos zu
  verlegen. In diesem Zusammenhang sollte auch BpPosV "abgeschafft" werden, da sich 
  die Gemeinsamkeiten von Positionen in Backtesting und WisoBoerse doch sehr in
  Grenzen halten.
- 04.08.17: Der für das Pyramidisieren notwendige Definitionsstring könnte in 
  BpTradeMgr::InitTrade gespeichert und bei den Positionseröffnungen übergeben
  werden.
- 15.11.17: Nach längerer (umzugsbedingter) Pause muss ich mich erst einmal wieder mit
  dem letzten Stand vertraut machen. Ich hatte offenbar damit begonnen, in der 
  Versionsbezeichnung einen Anteil hinzuzufügen, der auf eine Variante der
  Dateneingabe hinweist. Die einzugebenden Daten werden in eine Datenbank geschrieben.
  Damit soll erreicht werden, dass Rechnungen auch interaktiv wiederholt werden
  können z.B. für einen anderen Zeitbereich. Es sollen schließlich Parameter gefunden
  werden, mit denen gute Ergebnisse in jüngster Zeit erreicht werden können (und nicht
  hauptsächlich mit den Daten von vor dem Jahr 2000).
````

- ToDo:

- 08.07.14: Als zusätzliche Option eine "Verschiebung/Vergrößerung/Verkleinerung der
  Spektren analog zu WisoBörse einbauen. Als Beispiel TAxis::ExecuteEvent() nehmen.
	Dort wird allerdings nur TPad::ExecuteEventAxis() aufgerufen, wo der eigentliche
	Code steht. Die Fälle "kWheelUp" und "kWheelDown" sollten dahingehend verändert
	werden, dass nicht nur mit den Bins "gearbeitet" wird, sondern der Bereich der
	y-Achse verändert wird.
- 26.04.20: Zeitrahmen Bp::kSing abschaffen. Es wird nur noch Bp::kMult verwendet.
Dazu wird in einem ersten Schritt BpMultMgr::fZeiRa mit Bp::kMult initialisiert und
in der Eingabe weggelassen. 27.12.20: Das hab ich mir inzwischen anders überlegt.
Beide Möglichkeiten haben ihre Berechtigung (und Anwendungen).
