---
layout: single
title: Qt Klassen
permalink: thems/tq
sidebar:
  nav: thems
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

## Einleitung

25.03.21: Wegen der ständigen Schwierigkeiten mit Root soll nun doch wieder auf
[Qt](https://doc.qt.io/qt-5/index.html) zurückgegriffen werden. Zunächst hatte ich
versucht, die alte Version aus 2012 "wiederzubeleben". Das erwies sich als nicht
so erfreulich, da es dort noch eine TqChart Klasse gab, die ich inzwischen in der
Root-Variante Rt abgeschafft habe. Deshalb soll jetzt eine ähnliche Struktur 
verwendet werden, bei der RtMf (MainFrame) durch TqMw (MainWindow) und RtPlot durch
TqPlot ersetzt werden.

## Sql
26.04.21: Bevor Sql verwendet werden kann, muss das entsprechende Plugin installiert
werden: [How to Build the ODBC Plugin on Windows](https://doc.qt.io/qt-5/sql-driver.html#how-to-build-the-odbc-plugin-on-windows).
<br> cd %QTDIR%\\qtbase\\src\\plugins\\sqldrivers
<br> qmake
<br> nmake sub-odbc
<br> Dazu sollte in einem Developer Command Prompt for VS 2019 geschehen, damit
nmake verfägbar ist. (Eventuell könnte noch ein nmake install notwendig sein???).

## Qt Charts
21.05.21: Als Ersatz für Qwt habe ich versucht, das Graphik-Paket von Qt, Charts,
zu verwenden. Die entsprechenden Klassen sind mit 'Tc...' bezeichnet. Sehr weit bin
ich damit noch nicht gekommen. Ich habe aber das Gefühl, dass der Zeitaufwand doch
recht hoch werden dürfte. Deshalb werde ich erst mal wieder Qwt (Klassen Tq...)
verwenden. Der Stand meiner Bemühungen hinsichtlich Qt Charts wird erst einmal in
der Variante v1.01 aufgehoben für eventuelle spätere Weiterverwendung.
