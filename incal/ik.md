---
title: "Ik: Tests zu Indikatoren"
layout: single
permalink: incal/ik
author_profile: false
sidebar:
  nav: incal
toc: true  
---

## Einleitung

19.05.22: Vor einiger Zeit hatte ich begonnen, für den Test von Indikatoren jeweils eigene Klassen zu verwenden. die alle von Bp::It abgeleitet sind. Vorläufig werden diese Klasssen weiter verwendet, obwohl das doch ein recht umständliches Verfahren ist. Viel einfacher erscheint mir aus heutiger Sicht die Eingabe von *.int Files zu sein, bei denen der Compilationsschritt entfällt. Diese Files werden in Bp::IoMgr::ParseIn() direkt ausgewertet, was insbesondere bei Indikatoren recht einfach ist.

20.07.22: Aufrufe mit PsExa verwenden die Bp::It-Klassen, Aufrufe mit PsInt lesen ````*.int````, bzw. ````*.md```` Files ein.

<!-- @section WkIkTdS Supertrend-Indikator -->
## Supertrend-Indikator

<!-- - 30.07.22: @ref IkTdS

Was | Wie
---- | -------------
Bp::ItTdS:| PsExa 'IkTt,TdS,V2' '-dS 11' Ik\\TdS\\2\\IkTdSV2 BTD
IkTdS.md, Dax| PsInt 'Ik\\IkTdS,V1' '-dS 11' Ik\\TdS\\1\\IkTdSV1 BTD
IkTdS.md, Dax,RtM| PsInt 'Ik\\IkTdS,V1' '-dS 11' Ik\\TdS\\1\\IkTdSV1T BT
IkTdS.md, Dax, mit Glättung| PsInt 'Ik\\IkTdS,V11' '-dS 11' Ik\\TdS\\1\\IkTdSV11 BTD
IkTdS.md:| PsInt 'Ik\\IkTdS,V2' '-dS 11' Ik\\TdS\\2\\IkTdSV2 BTD -->

- 14.02.24: Umstellung auf flexiblere Dateneingabe mit Makro
[IkTdS.C](file:///C:/Users/User/BsTd/Src/Work/In/Ik/IkTdS.C) oder Text-File
[IkTdS.txt](file:///C:/Users/User/BsTd/Src/Work/In/Ik/IkTdS.txt)
- 05.03.24: Umstellung auf bs-mm-doc mit Macro
[IkTdS.C](./ik/IkTdS.C) oder Text-file
[IkTdS.txt](./ik/IkTdS.txt) oder
[IkTdS.C](file:///C:/Users/User/BsTd/BsWb/bs-mm/incal/ik/IkTdS.C)
 
<!-- [IkTdS.C](C:/Users/User/BsTd/BsWb/bs-jtd/coll/_ik/IkTdS.C) und
[IkTdS.txt](C:/Users/User/BsTd/BsWb/bs-jtd/coll/_ik/IkTdS.txt), bzw. 
[IkTdS_C.txt](/ik/IkTdS_C.txt) und
[IkTdS.txt](/ik/IkTdS.txt) sowie
und
[IkTdS.C](/ik/IkTdS.C)
und
{% for fc in site.static_files %}
  {% if fc.path contains 'incal/ik/IkTdS.C' %}
    {{ fc.name }}
  {% endif %}
{% endfor %}
[IkTdS.txt](../../coll/_ik/IkTdS.txt)
[IkTdS.txt](http://localhost:4000/coll/_inda/IkTdS.txt)
[IkTdS](IkTdS.md)
[IkTdS.md](//_iks/IkTdS.html)
[IkTdS.C](C:/Users/User/BsTd/BsWb/bs-jtd/docs/_inda/ik/IkTdS.txt)
[IkTdS.txt](File.join(File.dirname(__FILE__), '../../_inda/ik/IkTdS.txt') -->

Was | Wie
---- | -------------
IkTdS.C, Dax,RtM| Run '-Mac Ik IkTdS.C("V1")' '-dS 11' Ik\\TdS\\1\\IkTdSV1M BT
IkTdS.C, Fond,RtM| Run '-Mac Ik IkTdS.C("V2")' '-dS 11' Ik\\TdS\\2\\IkTdSV2M BT
IkTdS.txt,Dax,RtM| Run '-Tx2 Ik IkTdS V1' '-dS 11' Ik\\TdS\\1\\IkTdSV1 BT
IkTdS.txt,Fond,RtM| Run '-Tx2 Ik IkTdS V2' '-dS 11' Ik\\TdS\\2\\IkTdSV2 BT



<!-- @section WkIkZz Zig-Zag-Indikator -->
## Zig-Zag-Indikator

<!-- \subpage IkZz
Was | Wie
---- | -------------
Dax| PsInt 'Ik\\IkZz,V1' '-dS 11' Ik\\Zz\\1\\IkZzV1 BTD
Fond| PsInt 'Ik\\IkZz,V2' '-dS 11' Ik\\Zz\\2\\IkZzV2 BTD -->

- 16.02.24: Umstellung auf flexiblere Dateneingabe mit Makro
[IkZz.C](file:///C:/Users/User/BsTd/Src/Work/In/Ik/IkZz.C) oder Text-File
[IkZz.txt](file:///C:/Users/User/BsTd/Src/Work/In/Ik/IkZz.txt)
- 06.03.24: Umstellung auf bs-jtd:
[IkZz.C](/ik/IkZz.C) und
[IkZz.txt](/ik/IkZz.txt) 
<!-- und
[IkTdS_C_txt](/ik/IkZz_C.txt) -->

<!-- [IkZz.C](C:/Users/User/BsTd/BsWb/bs-jtd/coll/_ik/IkZz.C) und
[IkZz.txt](C:/Users/User/BsTd/BsWb/bs-jtd/coll/_ik/IkZz.txt) -->


Was | Wie
---- | -------------
Dax| Run '-Tx2 Ik IkZz V1' '-dS 11' Ik\\Zz\\1\\IkZzV1 BT
Dax| Run '-Mac Ik IkZz.C(1)' '-dS 11' Ik\\Zz\\1\\IkZzV1M BT
Fond| Run '-Tx2 Ik IkZz V2' '-dS 11' Ik\\Zz\\2\\IkZzV2 BT
Fond| Run '-Mac Ik IkZz.C(2)' '-dS 11' Ik\\Zz\\2\\IkZzV2M BT
