---
layout: single
title: Root Klassen
permalink: thems/rt
sidebar:
  nav: thems
toc: true 
---

## Einleitung

17.05.18: In diesem Verzeichnis sind die Klassen zusammengefasst, die von 
Root-Klassen abgeleitet sind und meistens der Darstellung der Ergebnisse dienen.

## RtPlot.cxx

- 17.05.18: Mit den Klassen in dieser Datei wird die unmittelbare Darstellung der
Ergebnisse insbesondere aus Backtestrechnungen vorgenommen. Daneben werden aber 
auch die Inhalte aus der zu Wiso-Börse gehörenden Datenbank dargestellt. Hier 
geht es im Wesentlichen um die real durchgeführten Transaktionen und die 
entsprechenden Positionen. Um die Darstellung zu vereinfachen, hatte ich für 
Transaktionen und Positionen sowohl aus Backtests als auch aus Wiso-Bürse 
gemeinsame Basisklassen eingeführt, die dann zur einheitlichen Darstellung
genutzt wurden. Nun haben aber Backtests und Wiso-Börse überhaupt nichts miteinander
zu tun, und diese Kopplung über die Basisklassen wird wieder beseitigt.
Damit sind dann für die Darstellung auch hier getrennte Klassen notwendig. Neben
RtPlotPos gibt es RtPlotPosWb und neben TrPlotTra gibt es RtPlotTraWb für
Positionen und Transaktionen.
- 18.05.18: Basisklassen BpPosV und BpTraV werden nicht mehr benutzt, und alles
scheint zu funktionieren. Allerdings gibt es RtPlotTraMk nur für BpTra, und nicht
für BpTraWb. Auch frage ich mich, ob diese Klassen für die Darstellung von 
Positionen  und Transaktionen überhaupt nötig sind, oder ob es simple Methoden in
RtPlot auch tun würden.
