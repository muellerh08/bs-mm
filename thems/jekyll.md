---
layout: single
title: Jekyll
permalink: thems/jekyll
sidebar:
  nav: thems
toc: true 
---
21.02.24: Diese Seite neu angelegt für alles, was Jekyll betrifft.

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

21.02.24: Die [ROOT Web Site](https://github.com/root-project/web?tab=readme-ov-file#root-web-site) 
basiert auf [Jekyll](https://jekyllrb.com/) und ist im Web der Startpunkt für die Root-Doku. Etwas in dieser
Richtung ist für die BsTd-Seite vorgesehen.

## Installation

- 21.02.24: [Jekyll on Windows](https://jekyllrb.com/docs/installation/windows/): "The easiest way to install Ruby 
and Jekyll is by using the [RubyInstaller](https://rubyinstaller.org/) for Windows.":
- Ruby+Devkit 3.2.3-1 (x64) heruntergeladen von https://rubyinstaller.org/downloads/ und installiert.
- ridk install step: Protokoll siehe [240221ridk](#240221ridk).
  - siehe [Adding Links in Markdown](https://itsfoss.com/markdown-links/)
- new command prompt: gem install jekyll bundler: Protokoll siehe [240221gem](#240221gem).
- gem update --system 3.5.6: "RubyGems system software updated", siehe [240221up](#240221up). 

## Protokolle
 
### 240221ridk

````
_____       _           _____           _        _ _         ___
|  __ \     | |         |_   _|         | |      | | |       |__ \
| |__) |   _| |__  _   _  | |  _ __  ___| |_ __ _| | | ___ _ __ ) |
|  _  / | | | '_ \| | | | | | | '_ \/ __| __/ _` | | |/ _ \ '__/ /
| | \ \ |_| | |_) | |_| |_| |_| | | \__ \ || (_| | | |  __/ | / /_
|_|  \_\__,_|_.__/ \__, |_____|_| |_|___/\__\__,_|_|_|\___|_||____|
                    __/ |           _
                   |___/          _|_ _  __   | | o __  _| _     _
                                   | (_) |    |^| | | |(_|(_)\^/_>

   1 - MSYS2 base installation
   2 - MSYS2 system update (optional)
   3 - MSYS2 and MINGW development toolchain

Which components shall be installed? If unsure press ENTER [1,3]

> sh -lc true
'C:\WINDOWS\system32\drivers\etc\hosts' -> '/etc/hosts'
'C:\WINDOWS\system32\drivers\etc\protocol' -> '/etc/protocols'
'C:\WINDOWS\system32\drivers\etc\services' -> '/etc/services'
'C:\WINDOWS\system32\drivers\etc\networks' -> '/etc/networks'
gpg: /etc/pacman.d/gnupg/trustdb.gpg: trust-db erzeugt
gpg: keine ultimativ vertrauenswürdigen Schlüssel gefunden
gpg: starting migration from earlier GnuPG versions
gpg: porting secret keys from '/etc/pacman.d/gnupg/secring.gpg' to gpg-agent
gpg: migration succeeded
==> Pacman Hauptschlüssel generieren. Kann eine Weile dauern.
gpg: Generating pacman keyring master key...
gpg: Verzeichnis `/etc/pacman.d/gnupg/openpgp-revocs.d' erzeugt
gpg: Widerrufzertifikat wurde als '/etc/pacman.d/gnupg/openpgp-revocs.d/4F2D6EFD27B5271D6E3DAB59C9E6C236262D4B0B.rev' gespeichert.
gpg: Done
==> Aktualisiere Trust-Datenbank...
gpg: marginals needed: 3  completes needed: 1  trust model: pgp
gpg: Tiefe: 0  gültig:   1  signiert:   0  Vertrauen: 0-, 0q, 0n, 0m, 0f, 1u
==> Füge Schlüssel aus msys2.gpg hinzu...
==> Signiere die vertrauenswürdigen Schlüssel im Schlüsselbund lokal...
  -> Signiere Schlüssel 5 lokal...
==> Importiere die Vertrauenswerte des Benutzers...
gpg: setting ownertrust to 4
gpg: setting ownertrust to 4
gpg: setting ownertrust to 4
gpg: setting ownertrust to 4
gpg: setting ownertrust to 4
==> Mache widerrufene Schlüssel im Schlüsselbund unbrauchbar...
  -> Mache Schlüssel 4 unbrauchbar...
==> Aktualisiere Trust-Datenbank...
gpg: marginals needed: 3  completes needed: 1  trust model: pgp
gpg: Tiefe: 0  gültig:   1  signiert:   5  Vertrauen: 0-, 0q, 0n, 0m, 0f, 1u
gpg: Tiefe: 1  gültig:   5  signiert:   7  Vertrauen: 0-, 0q, 0n, 5m, 0f, 0u
gpg: Tiefe: 2  gültig:   4  signiert:   2  Vertrauen: 4-, 0q, 0n, 0m, 0f, 0u
gpg: nächste "Trust-DB"-Pflichtüberprüfung am 2024-04-10
gpg: Fehler beim automatischen holen von `alexey.pawlow@gmail.com' über `WKD': Keine Daten
gpg: error reading key: Keine Daten
gpg: 1 Schlüssel wird per hkps://keyserver.ubuntu.com aktualisiert
gpg: Schlüssel F40D263ECA25678A: "Alexey Pavlov (Alexpux) <alexey.pawlow@gmail.com>" nicht geändert
gpg: Anzahl insgesamt bearbeiteter Schlüssel: 1
gpg:                             unverändert: 1
gpg: Fehler beim automatischen holen von `david.macek.0@gmail.com' über `WKD': Keine Daten
gpg: error reading key: Keine Daten
gpg: 1 Schlüssel wird per hkps://keyserver.ubuntu.com aktualisiert
gpg: Schlüssel 790AE56A1D3CFDDC: "David Macek (MSYS2 master key) <david.macek.0@gmail.com>" nicht geändert
gpg: Anzahl insgesamt bearbeiteter Schlüssel: 1
gpg:                             unverändert: 1
gpg: Fehler beim automatischen holen von `martellmalone@gmail.com' über `WKD': Keine Daten
gpg: error reading key: Keine Daten
gpg: 1 Schlüssel wird per hkps://keyserver.ubuntu.com aktualisiert
gpg: Schlüssel DA7EF2ABAEEA755C: "Martell Malone (martell) <martellmalone@gmail.com>" nicht geändert
gpg: Anzahl insgesamt bearbeiteter Schlüssel: 1
gpg:                             unverändert: 1
gpg: Fehler beim automatischen holen von `reiter.christoph@gmail.com' über `WKD': Keine Daten
gpg: error reading key: Keine Daten
gpg: 1 Schlüssel wird per hkps://keyserver.ubuntu.com aktualisiert
gpg: Schlüssel 755B8182ACD22879: "Christoph Reiter (MSYS2 master key) <reiter.christoph@gmail.com>" nicht geändert
gpg: Anzahl insgesamt bearbeiteter Schlüssel: 1
gpg:                             unverändert: 1
gpg: Fehler beim automatischen holen von `icquinteiro@gmail.com' über `WKD': Keine Daten
gpg: error reading key: Keine Daten
gpg: 1 Schlüssel wird per hkps://keyserver.ubuntu.com aktualisiert
gpg: Schlüssel 9F418C233E652008: "Ignacio Casal Quinteiro <icquinteiro@gmail.com>" nicht geändert
gpg: Anzahl insgesamt bearbeiteter Schlüssel: 1
gpg:                             unverändert: 1
gpg: Fehler beim automatischen holen von `mingw.android@gmail.com' über `WKD': Keine Daten
gpg: error reading key: Keine Daten
gpg: 1 Schlüssel wird per hkps://keyserver.ubuntu.com aktualisiert
gpg: Schlüssel BBE514E53E0D0813: "Ray Donnelly (MSYS2 Developer - master key) <mingw.android@gmail.com>" nicht geändert
gpg: Anzahl insgesamt bearbeiteter Schlüssel: 1
gpg:                             unverändert: 1
gpg: Fehler beim automatischen holen von `alexpux@gmail.com' über `WKD': Keine Daten
gpg: error reading key: Keine Daten
gpg: 1 Schlüssel wird per hkps://keyserver.ubuntu.com aktualisiert
gpg: Schlüssel 5F92EFC1A47D45A1: "Alexey Pavlov (Alexpux) <alexpux@gmail.com>" nicht geändert
gpg: Anzahl insgesamt bearbeiteter Schlüssel: 1
gpg:                             unverändert: 1
gpg: Fehler beim automatischen holen von `david.macek.0@gmail.com' über `WKD': Keine Daten
gpg: error reading key: Keine Daten
gpg: 1 Schlüssel wird per hkps://keyserver.ubuntu.com aktualisiert
gpg: Schlüssel 974C8BE49078F532: "David Macek <david.macek.0@gmail.com>" nicht geändert
gpg: Anzahl insgesamt bearbeiteter Schlüssel: 1
gpg:                             unverändert: 1
gpg: Fehler beim automatischen holen von `reiter.christoph@gmail.com' über `WKD': Keine Daten
gpg: error reading key: Keine Daten
gpg: 1 Schlüssel wird per hkps://keyserver.ubuntu.com aktualisiert
gpg: Schlüssel FA11531AA0AA7F57: "Christoph Reiter (MSYS2 development key) <reiter.christoph@gmail.com>" nicht geändert
gpg: Anzahl insgesamt bearbeiteter Schlüssel: 1
gpg:                             unverändert: 1
gpg: Fehler beim automatischen holen von `me@martellmalone.com' über `WKD': Kein Name
gpg: error reading key: Kein Name
gpg: 1 Schlüssel wird per hkps://keyserver.ubuntu.com aktualisiert
gpg: Schlüssel 794DCF97F93FC717: "Martell Malone (martell) <me@martellmalone.com>" nicht geändert
gpg: Anzahl insgesamt bearbeiteter Schlüssel: 1
gpg:                             unverändert: 1
gpg: Fehler beim automatischen holen von `martellmalone@gmail.com' über `WKD': Keine Daten
gpg: error reading key: Keine Daten
gpg: 1 Schlüssel wird per hkps://keyserver.ubuntu.com aktualisiert
gpg: Schlüssel D595C9AB2C51581E: "Martell Malone (MSYS2 Developer) <martellmalone@gmail.com>" nicht geändert
gpg: Anzahl insgesamt bearbeiteter Schlüssel: 1
gpg:                             unverändert: 1
gpg: Fehler beim automatischen holen von `mingw.android@gmail.com' über `WKD': Keine Daten
gpg: error reading key: Keine Daten
gpg: 1 Schlüssel wird per hkps://keyserver.ubuntu.com aktualisiert
gpg: Schlüssel 4DF3B7664CA56930: "Ray Donnelly (MSYS2 Developer) <mingw.android@gmail.com>" nicht geändert
gpg: Anzahl insgesamt bearbeiteter Schlüssel: 1
gpg:                             unverändert: 1
MSYS2 seems to be properly installed
Install MSYS2 and MINGW development toolchain ...
> pacman -S --needed --noconfirm autoconf autogen automake-wrapper diffutils file gawk grep libtool m4 make patch sed texinfo texinfo-tex wget mingw-w64-ucrt-x86_64-binutils mingw-w64-ucrt-x86_64-crt-git mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-gcc-libs mingw-w64-ucrt-x86_64-headers-git mingw-w64-ucrt-x86_64-libmangle-git mingw-w64-ucrt-x86_64-libwinpthread-git mingw-w64-ucrt-x86_64-make mingw-w64-ucrt-x86_64-tools-git mingw-w64-ucrt-x86_64-winpthreads-git pkgconf mingw-w64-ucrt-x86_64-pkgconf
Warnung: autoconf-wrapper-20221207-2 ist aktuell -- Überspringe
Warnung: autogen-5.18.16-5 ist aktuell -- Überspringe
Warnung: automake-wrapper-20221207-2 ist aktuell -- Überspringe
Warnung: diffutils-3.10-1 ist aktuell -- Überspringe
Warnung: file-5.45-1 ist aktuell -- Überspringe
Warnung: gawk-5.3.0-1 ist aktuell -- Überspringe
Warnung: grep-1~3.0-6 ist aktuell -- Überspringe
Warnung: libtool-2.4.7-3 ist aktuell -- Überspringe
Warnung: m4-1.4.19-2 ist aktuell -- Überspringe
Warnung: make-4.4.1-1 ist aktuell -- Überspringe
Warnung: patch-2.7.6-2 ist aktuell -- Überspringe
Warnung: sed-4.9-1 ist aktuell -- Überspringe
Warnung: texinfo-7.1-2 ist aktuell -- Überspringe
Warnung: texinfo-tex-7.1-2 ist aktuell -- Überspringe
Warnung: wget-1.21.4-1 ist aktuell -- Überspringe
Warnung: mingw-w64-ucrt-x86_64-binutils-2.41-3 ist aktuell -- Überspringe
Warnung: mingw-w64-ucrt-x86_64-crt-git-11.0.0.r551.g86a5e0f41-1 ist aktuell -- Überspringe
Warnung: mingw-w64-ucrt-x86_64-gcc-13.2.0-3 ist aktuell -- Überspringe
Warnung: mingw-w64-ucrt-x86_64-gcc-libs-13.2.0-3 ist aktuell -- Überspringe
Warnung: mingw-w64-ucrt-x86_64-headers-git-11.0.0.r551.g86a5e0f41-1 ist aktuell -- Überspringe
Warnung: mingw-w64-ucrt-x86_64-libmangle-git-11.0.0.r551.g86a5e0f41-1 ist aktuell -- Überspringe
Warnung: mingw-w64-ucrt-x86_64-libwinpthread-git-11.0.0.r551.g86a5e0f41-1 ist aktuell -- Überspringe
Warnung: mingw-w64-ucrt-x86_64-make-4.4.1-1 ist aktuell -- Überspringe
Warnung: mingw-w64-ucrt-x86_64-tools-git-11.0.0.r551.g86a5e0f41-1 ist aktuell -- Überspringe
Warnung: mingw-w64-ucrt-x86_64-winpthreads-git-11.0.0.r551.g86a5e0f41-1 ist aktuell -- Überspringe
Warnung: pkgconf-2.1.0-1 ist aktuell -- Überspringe
Warnung: mingw-w64-ucrt-x86_64-pkgconf-1~2.1.0-1 ist aktuell -- Überspringe
 Es gibt nichts zu tun
Install MSYS2 and MINGW development toolchain succeeded

You can use 'ridk enable' to activate the MSYS2 tools on the command prompt.

   1 - MSYS2 base installation
   2 - MSYS2 system update (optional)
   3 - MSYS2 and MINGW development toolchain

Which components shall be installed? If unsure press ENTER []
````

### 240221gem

````
C:\Users\User>gem install jekyll bundler
Fetching webrick-1.8.1.gem
Fetching forwardable-extended-2.6.0.gem
Fetching pathutil-0.16.2.gem
Fetching safe_yaml-1.0.5.gem
Fetching rouge-4.2.0.gem
Fetching unicode-display_width-2.5.0.gem
Fetching terminal-table-3.0.2.gem
Fetching mercenary-0.4.0.gem
Fetching liquid-4.0.4.gem
Fetching kramdown-2.4.0.gem
Fetching kramdown-parser-gfm-1.1.0.gem
Fetching ffi-1.16.3-x64-mingw-ucrt.gem
Fetching rb-inotify-0.10.1.gem
Fetching rb-fsevent-0.11.2.gem
Fetching listen-3.8.0.gem
Fetching jekyll-watch-2.2.1.gem
Fetching google-protobuf-3.25.3-x64-mingw-ucrt.gem
Fetching sass-embedded-1.71.1-x64-mingw-ucrt.gem
Fetching jekyll-sass-converter-3.0.0.gem
Fetching concurrent-ruby-1.2.3.gem
Fetching i18n-1.14.1.gem
Fetching http_parser.rb-0.8.0.gem
Fetching eventmachine-1.2.7.gem
Fetching em-websocket-0.5.3.gem
Fetching jekyll-4.3.3.gem
Fetching colorator-1.1.0.gem
Fetching public_suffix-5.0.4.gem
Fetching addressable-2.8.6.gem
Successfully installed webrick-1.8.1
Successfully installed unicode-display_width-2.5.0
Successfully installed terminal-table-3.0.2
Successfully installed safe_yaml-1.0.5
Successfully installed rouge-4.2.0
Successfully installed forwardable-extended-2.6.0
Successfully installed pathutil-0.16.2
Successfully installed mercenary-0.4.0
Successfully installed liquid-4.0.4
Successfully installed kramdown-2.4.0
Successfully installed kramdown-parser-gfm-1.1.0
Successfully installed ffi-1.16.3-x64-mingw-ucrt
Successfully installed rb-inotify-0.10.1
Successfully installed rb-fsevent-0.11.2
Successfully installed listen-3.8.0
Successfully installed jekyll-watch-2.2.1
Successfully installed google-protobuf-3.25.3-x64-mingw-ucrt
Successfully installed sass-embedded-1.71.1-x64-mingw-ucrt
Successfully installed jekyll-sass-converter-3.0.0
Successfully installed concurrent-ruby-1.2.3
Successfully installed i18n-1.14.1
Temporarily enhancing PATH for MSYS/MINGW...
Building native extensions. This could take a while...
Successfully installed http_parser.rb-0.8.0
Building native extensions. This could take a while...
Successfully installed eventmachine-1.2.7
Successfully installed em-websocket-0.5.3
Successfully installed colorator-1.1.0
Successfully installed public_suffix-5.0.4
Successfully installed addressable-2.8.6
Successfully installed jekyll-4.3.3
Parsing documentation for webrick-1.8.1
Installing ri documentation for webrick-1.8.1
Parsing documentation for unicode-display_width-2.5.0
Installing ri documentation for unicode-display_width-2.5.0
Parsing documentation for terminal-table-3.0.2
Installing ri documentation for terminal-table-3.0.2
Parsing documentation for safe_yaml-1.0.5
Installing ri documentation for safe_yaml-1.0.5
Parsing documentation for rouge-4.2.0
Installing ri documentation for rouge-4.2.0
Parsing documentation for forwardable-extended-2.6.0
Installing ri documentation for forwardable-extended-2.6.0
Parsing documentation for pathutil-0.16.2
Installing ri documentation for pathutil-0.16.2
Parsing documentation for mercenary-0.4.0
Installing ri documentation for mercenary-0.4.0
Parsing documentation for liquid-4.0.4
Installing ri documentation for liquid-4.0.4
Parsing documentation for kramdown-2.4.0
Installing ri documentation for kramdown-2.4.0
Parsing documentation for kramdown-parser-gfm-1.1.0
Installing ri documentation for kramdown-parser-gfm-1.1.0
Parsing documentation for ffi-1.16.3-x64-mingw-ucrt
Installing ri documentation for ffi-1.16.3-x64-mingw-ucrt
Parsing documentation for rb-inotify-0.10.1
Installing ri documentation for rb-inotify-0.10.1
Parsing documentation for rb-fsevent-0.11.2
Installing ri documentation for rb-fsevent-0.11.2
Parsing documentation for listen-3.8.0
Installing ri documentation for listen-3.8.0
Parsing documentation for jekyll-watch-2.2.1
Installing ri documentation for jekyll-watch-2.2.1
Parsing documentation for google-protobuf-3.25.3-x64-mingw-ucrt
Installing ri documentation for google-protobuf-3.25.3-x64-mingw-ucrt
Parsing documentation for sass-embedded-1.71.1-x64-mingw-ucrt
Installing ri documentation for sass-embedded-1.71.1-x64-mingw-ucrt
Parsing documentation for jekyll-sass-converter-3.0.0
Installing ri documentation for jekyll-sass-converter-3.0.0
Parsing documentation for concurrent-ruby-1.2.3
Installing ri documentation for concurrent-ruby-1.2.3
Parsing documentation for i18n-1.14.1
Installing ri documentation for i18n-1.14.1
Parsing documentation for http_parser.rb-0.8.0
unknown encoding name "chunked\r\n\r\n25" for ext/ruby_http_parser/vendor/http-parser-java/tools/parse_tests.rb, skipping
Installing ri documentation for http_parser.rb-0.8.0
Parsing documentation for eventmachine-1.2.7
Installing ri documentation for eventmachine-1.2.7
Parsing documentation for em-websocket-0.5.3
Installing ri documentation for em-websocket-0.5.3
Parsing documentation for colorator-1.1.0
Installing ri documentation for colorator-1.1.0
Parsing documentation for public_suffix-5.0.4
Installing ri documentation for public_suffix-5.0.4
Parsing documentation for addressable-2.8.6
Installing ri documentation for addressable-2.8.6
Parsing documentation for jekyll-4.3.3
Installing ri documentation for jekyll-4.3.3
Done installing documentation for webrick, unicode-display_width, terminal-table, safe_yaml, rouge, forwardable-extended, pathutil, mercenary, liquid, kramdown, kramdown-parser-gfm, ffi, rb-inotify, rb-fsevent, listen, jekyll-watch, google-protobuf, sass-embedded, jekyll-sass-converter, concurrent-ruby, i18n, http_parser.rb, eventmachine, em-websocket, colorator, public_suffix, addressable, jekyll after 24 seconds
Fetching bundler-2.5.6.gem
Successfully installed bundler-2.5.6
Parsing documentation for bundler-2.5.6
Installing ri documentation for bundler-2.5.6
Done installing documentation for bundler after 0 seconds
29 gems installed

A new release of RubyGems is available: 3.4.19 → 3.5.6!
Run `gem update --system 3.5.6` to update your installation.

C:\Users\User>jekyll -v
jekyll 4.3.3
````

### 240221up

````

C:\Users\User>gem update --system 3.5.6
Updating rubygems-update
Fetching rubygems-update-3.5.6.gem
Successfully installed rubygems-update-3.5.6
Parsing documentation for rubygems-update-3.5.6
Installing ri documentation for rubygems-update-3.5.6
Done installing documentation for rubygems-update after 1 seconds
Parsing documentation for rubygems-update-3.5.6
Done installing documentation for rubygems-update after 0 seconds
Installing RubyGems 3.5.6
  Successfully built RubyGem
  Name: bundler
  Version: 2.5.6
  File: bundler-2.5.6.gem
Bundler 2.5.6 installed
RubyGems 3.5.6 installed
Regenerating binstubs
Regenerating plugins
Parsing documentation for rubygems-3.5.6
Installing ri documentation for rubygems-3.5.6

# 3.5.6 / 2024-02-06

## Enhancements:

* Deep copy requirements in `Gem::Specification` and `Gem::Requirement`.
  Pull request [#7439](https://github.com/rubygems/rubygems/pull/7439) by
  flavorjones
* Change gem login message to clear up that username can be also used.
  Pull request [#7422](https://github.com/rubygems/rubygems/pull/7422) by
  VitaliySerov
* Add metadata for rubygems.org. Pull request
  [#7435](https://github.com/rubygems/rubygems/pull/7435) by m-nakamura145
* Improve gem login scope selection. Pull request
  [#7342](https://github.com/rubygems/rubygems/pull/7342) by williantenfen
* Vendor uri in RubyGems. Pull request
  [#7386](https://github.com/rubygems/rubygems/pull/7386) by
  deivid-rodriguez
* Installs bundler 2.5.6 as a default gem.

## Bug fixes:

* Skip to load commented out words. Pull request
  [#7413](https://github.com/rubygems/rubygems/pull/7413) by hsbt
* Fix rake runtime dependency warning for rake based extension. Pull
  request [#7395](https://github.com/rubygems/rubygems/pull/7395) by ntkme

# 3.5.5 / 2024-01-18

## Enhancements:

* Installs bundler 2.5.5 as a default gem.

## Bug fixes:

* Fix `require` activation conflicts when requiring default gems under
  some situations. Pull request
  [#7379](https://github.com/rubygems/rubygems/pull/7379) by
  deivid-rodriguez
* Use cache_home instead of data_home in default_spec_cache_dir. Pull
  request [#7331](https://github.com/rubygems/rubygems/pull/7331) by mrkn

## Documentation:

* Use squiggly heredocs in `Gem::Specification#description` documentation,
  so it doesn't add leading whitespace. Pull request
  [#7373](https://github.com/rubygems/rubygems/pull/7373) by bravehager

# 3.5.4 / 2024-01-04

## Enhancements:

* Always avoid "Updating rubygems-update" message. Pull request
  [#7335](https://github.com/rubygems/rubygems/pull/7335) by
  deivid-rodriguez
* Installs bundler 2.5.4 as a default gem.

## Bug fixes:

* Make `gem update --system` respect ruby version constraints. Pull
  request [#7334](https://github.com/rubygems/rubygems/pull/7334) by
  deivid-rodriguez

# 3.5.3 / 2023-12-22

## Enhancements:

* Installs bundler 2.5.3 as a default gem.

# 3.5.2 / 2023-12-21

## Enhancements:

* Support dynamic library loading with extension .so or .o. Pull request
  [#7241](https://github.com/rubygems/rubygems/pull/7241) by hogelog
* Installs bundler 2.5.2 as a default gem.

## Performance:

* Replace `object_id` comparison with identity Hash. Pull request
  [#7303](https://github.com/rubygems/rubygems/pull/7303) by amomchilov
* Use IO.copy_stream when reading, writing. Pull request
  [#6958](https://github.com/rubygems/rubygems/pull/6958) by martinemde

# 3.5.1 / 2023-12-15

## Enhancements:

* Installs bundler 2.5.1 as a default gem.

# 3.5.0 / 2023-12-15

## Security:

* Replace `Marshal.load` with a fully-checked safe gemspec loader. Pull
  request [#6896](https://github.com/rubygems/rubygems/pull/6896) by
  segiddins

## Breaking changes:

* Drop ruby 2.6 and 2.7 support. Pull request
  [#7116](https://github.com/rubygems/rubygems/pull/7116) by
  deivid-rodriguez
* Release package no longer includes test files. Pull request
  [#6781](https://github.com/rubygems/rubygems/pull/6781) by hsbt
* Hide `Gem::MockGemUi` from users. Pull request
  [#6623](https://github.com/rubygems/rubygems/pull/6623) by hsbt
* Deprecated `Gem.datadir` has been removed. Pull request
  [#6469](https://github.com/rubygems/rubygems/pull/6469) by hsbt

## Deprecations:

* Deprecate `Gem::Platform.match?`. Pull request
  [#6783](https://github.com/rubygems/rubygems/pull/6783) by hsbt
* Deprecate `Gem::List`. Pull request
  [#6311](https://github.com/rubygems/rubygems/pull/6311) by segiddins

## Features:

* The `generate_index` command can now generate compact index files and
  lives as an external `rubygems-generate_index` gem. Pull request
  [#7085](https://github.com/rubygems/rubygems/pull/7085) by segiddins
* Make `gem install` fallback to user installation directory if default
  gem home is not writable. Pull request
  [#5327](https://github.com/rubygems/rubygems/pull/5327) by duckinator
* Leverage ruby feature to warn when requiring default gems from stdlib
  that will be turned into bundled gems in the future. Pull request
  [#6840](https://github.com/rubygems/rubygems/pull/6840) by hsbt

## Performance:

* Use match? when regexp match data is unused. Pull request
  [#7263](https://github.com/rubygems/rubygems/pull/7263) by segiddins
* Fewer allocations in gem installation. Pull request
  [#6975](https://github.com/rubygems/rubygems/pull/6975) by segiddins
* Optimize allocations in `Gem::Version`. Pull request
  [#6970](https://github.com/rubygems/rubygems/pull/6970) by segiddins

## Enhancements:

* Warn for duplicate meta data links when building gems. Pull request
  [#7213](https://github.com/rubygems/rubygems/pull/7213) by etherbob
* Vendor `net-http`, `net-protocol`, `resolv`, and `timeout` to reduce
  conflicts between Gemfile gems and internal dependencies. Pull request
  [#6793](https://github.com/rubygems/rubygems/pull/6793) by
  deivid-rodriguez
* Remove non-transparent requirement added to prerelease gems. Pull
  request [#7226](https://github.com/rubygems/rubygems/pull/7226) by
  deivid-rodriguez
* Stream output from ext builds when --verbose. Pull request
  [#7240](https://github.com/rubygems/rubygems/pull/7240) by osyoyu
* Add missing services to CI detection and make it consistent between
  RubyGems and Bundler. Pull request
  [#7205](https://github.com/rubygems/rubygems/pull/7205) by nevinera
* Update generate licenses template to not freeze regexps. Pull request
  [#7154](https://github.com/rubygems/rubygems/pull/7154) by
  github-actions[bot]
* Don't check `LIBRUBY_RELATIVE` in truffleruby to signal a bash prelude
  in rubygems binstubs. Pull request
  [#7156](https://github.com/rubygems/rubygems/pull/7156) by
  deivid-rodriguez
* Update SPDX list and warn on deprecated identifiers. Pull request
  [#6926](https://github.com/rubygems/rubygems/pull/6926) by simi
* Simplify extended `require` to potentially fix some deadlocks. Pull
  request [#6827](https://github.com/rubygems/rubygems/pull/6827) by nobu
* Small refactors for `Gem::Resolver`. Pull request
  [#6766](https://github.com/rubygems/rubygems/pull/6766) by hsbt
* Use double-quotes instead of single-quotes consistently in warnings.
  Pull request [#6550](https://github.com/rubygems/rubygems/pull/6550) by
  hsbt
* Add debug message for `nil` version gemspec. Pull request
  [#6436](https://github.com/rubygems/rubygems/pull/6436) by hsbt
* Installs bundler 2.5.0 as a default gem.

## Bug fixes:

* Fix installing from source with same default bundler version already
  installed. Pull request
  [#7244](https://github.com/rubygems/rubygems/pull/7244) by
  deivid-rodriguez

## Documentation:

* Improve comment explaining the necessity of `write_default_spec` method.
  Pull request [#6563](https://github.com/rubygems/rubygems/pull/6563) by
  voxik

# 3.4.22 / 2023-11-09

## Enhancements:

* Update SPDX license list as of 2023-10-05. Pull request
  [#7040](https://github.com/rubygems/rubygems/pull/7040) by
  github-actions[bot]
* Remove unnecessary rescue. Pull request
  [#7109](https://github.com/rubygems/rubygems/pull/7109) by
  deivid-rodriguez
* Installs bundler 2.4.22 as a default gem.

## Bug fixes:

* Handle empty array at built-in YAML serializer. Pull request
  [#7099](https://github.com/rubygems/rubygems/pull/7099) by hsbt
* Ignore non-tar format `.gem` files during search. Pull request
  [#7095](https://github.com/rubygems/rubygems/pull/7095) by dearblue
* Allow explicitly uninstalling multiple versions of same gem. Pull
  request [#7063](https://github.com/rubygems/rubygems/pull/7063) by
  kstevens715

## Performance:

* Avoid regexp match on every call to `Gem::Platform.local`. Pull request
  [#7104](https://github.com/rubygems/rubygems/pull/7104) by segiddins

## Documentation:

* Get `Gem::Specification#extensions_dir` documented. Pull request
  [#6218](https://github.com/rubygems/rubygems/pull/6218) by
  deivid-rodriguez

# 3.4.21 / 2023-10-17

## Enhancements:

* Abort `setup.rb` if Ruby is too old. Pull request
  [#7011](https://github.com/rubygems/rubygems/pull/7011) by
  deivid-rodriguez
* Remove usage of Dir.chdir that only execute a subprocess. Pull request
  [#6930](https://github.com/rubygems/rubygems/pull/6930) by segiddins
* Freeze more strings in generated gemspecs. Pull request
  [#6974](https://github.com/rubygems/rubygems/pull/6974) by segiddins
* Use pure-ruby YAML parser for loading configuration at RubyGems. Pull
  request [#6615](https://github.com/rubygems/rubygems/pull/6615) by hsbt
* Installs bundler 2.4.21 as a default gem.

## Documentation:

* Update suggested variable for bindir. Pull request
  [#7028](https://github.com/rubygems/rubygems/pull/7028) by hsbt
* Fix invalid links in documentation. Pull request
  [#7008](https://github.com/rubygems/rubygems/pull/7008) by simi

# 3.4.20 / 2023-09-27

## Enhancements:

* Raise `Gem::Package::FormatError` when gem encounters corrupt EOF.
  Pull request [#6882](https://github.com/rubygems/rubygems/pull/6882)
  by martinemde
* Allow skipping empty license `gem build` warning by setting license to
  `nil`. Pull request
  [#6879](https://github.com/rubygems/rubygems/pull/6879) by jhong97
* Update SPDX license list as of 2023-06-18. Pull request
  [#6891](https://github.com/rubygems/rubygems/pull/6891) by
  github-actions[bot]
* Update SPDX license list as of 2023-04-28. Pull request
  [#6642](https://github.com/rubygems/rubygems/pull/6642) by segiddins
* Update SPDX license list as of 2023-01-26. Pull request
  [#6310](https://github.com/rubygems/rubygems/pull/6310) by segiddins
* Installs bundler 2.4.20 as a default gem.

## Bug fixes:

* Fixed false positive SymlinkError in symbolic link directory. Pull
  request [#6947](https://github.com/rubygems/rubygems/pull/6947) by
  negi0109
* Ensure that loading multiple gemspecs with legacy YAML class references
  does not warn. Pull request
  [#6889](https://github.com/rubygems/rubygems/pull/6889) by segiddins
* Fix NoMethodError when choosing a too big number from `gem uni` list.
  Pull request [#6901](https://github.com/rubygems/rubygems/pull/6901) by
  amatsuda

## Performance:

* Reduce allocations for stub specifications. Pull request
  [#6972](https://github.com/rubygems/rubygems/pull/6972) by segiddins


------------------------------------------------------------------------------

RubyGems installed the following executables:
        C:/Ruby32-x64/bin/gem
        C:/Ruby32-x64/bin/bundle
        C:/Ruby32-x64/bin/bundler

Ruby Interactive (ri) documentation was installed. ri is kind of like man
pages for Ruby libraries. You may access it like this:
  ri Classname
  ri Classname.class_method
  ri Classname#instance_method
If you do not wish to install this documentation in the future, use the
--no-document flag, or set it as the default in your ~/.gemrc file. See
'gem help env' for details.

RubyGems system software updated
````
