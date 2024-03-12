---
title: "Installation"
layout: single
permalink: /docs/install/
comments: true
sidebar:
  nav: doc_nav
toc: true  
---
# Readme zur Installation

- 28.02.24: Der Hinweis auf dieses Projekt ist vom Ende des Abschnittes [Remote theme method](
  https://github.com/root-project/minimal-mistakes?tab=readme-ov-file#remote-theme-method)
- [Minimal Mistakes remote theme starter]( 
    https://github.com/mmistakes/mm-github-pages-starter?tab=readme-ov-file#minimal-mistakes-remote-theme-starter): Dort steht
    Click Use this template button above for the quickest method of getting started -> Damit wurde
    das Projekt [muellerh08/mm-github-starter](https://github.com/muellerh08/mm-github-starter)
    erzeugt, das am 29.02.24 in bs-mm-doc umbenannt wurde.
- Davon wird ein lokaler Clone erzeugt in der git-bash, siehe [240228-1clone](#240228-1clone).
- Der 1. Versuch, siehe [240228-2serv](#240228-2serve) endet wieder mit dem Fehler:
  "GitHub Metadata: No GitHub API authentication could be found. Some fields may be missing or have
  incorrect data."
  Aber in diesem Projekt gibt es unter [Troubleshooting](
    https://github.com/muellerh08/mm-github-starter?tab=readme-ov-file#troubleshooting)
  den Punkt:
  - [Configuring GitHub Metadata](
    https://github.com/jekyll/github-metadata/blob/master/docs/configuration.md#configuration) to work properly when developing locally and avoid No GitHub API authentication could be found. Some fields may be missing or have incorrect data. warnings.
- Ergänzung von Feldern wie
  - 'repository: muellerh08/bs-mm-doc'

  in _config.yml beseitigen zwar diesen Fehler, dafür kommt immer wieder: "GitHub Metadata: No GitHub API authentication could be found.
  Some fields may be missing or have incorrect data." Dieser Fehler kann mit dem Eintrag
  - github: [metadata]

  (,den ich irgenwo gesehen, aber nicht wiedergefunden habe) beseitigt werden.
- Dann gibt es noch ein fehlendes Programm

  ```text 
  Auto-regeneration: enabled for 'C:/Users/User/BsTd/BsDoc/mm-github-starter/mm-github-starter'
  <internal:C:/Ruby32-x64/lib/ruby/site_ruby/3.2.0/rubygems/core_ext/kernel_require.rb>:37:in `require': cannot load such file -- webrick (LoadError)
  ```

  das aber mit den Eintrag 'gem "webrick"' in dem Gemfile ergänzt werden kann. Damit funktioniert alles, siehe [240228-3inServ](#240228-3inserve)
- 29.02.24: Es gibt ein Projekt [jekyll/github-metadata](
  https://github.com/jekyll/github-metadata?tab=readme-ov-file), das offenbar recht einfach anzuwenden sein sollte. Aber ich hab noch nirgendwo eine Anwendung gesehen.
- Wenn '#github: [metadata]' auskommentiert wird, kommt wieder der Fehler   GitHub Metadata: No GitHub API authentication could be found....
  Aber die Seite erscheint trotzdem???
- Auch mit dem Eintrag 'remote_theme: "root-project/minimal-mistakes@root-patches"' funktioniert alles. Damit wird die von root modifizierte Version benutzt.
- Github Repository umbenannt von mm-github-starter zu bs-mm-doc.
  - Lokal: ...\mm-github-starter\mm-github-starter umbenannt in ...\mm-github-starter\bs-mm-doc
  - Kontrolle ob die Umbennung "funktioniert"

  ````text
  Push 1 branch to origin:
  POST git-receive-pack (876 bytes)
  remote: This repository moved. Please use the new location:        
  remote:   https://github.com/muellerh08/bs-mm-doc.git        
  Pushing to https://github.com/muellerh08/mm-github-starter.git
  To https://github.com/muellerh08/mm-github-starter.git
     eab4125..79f504b  master -> master
  updating local tracking ref 'refs/remotes/origin/master'

  ````

  - Ist zwar offenbar an der "richtigen" Stelle angekommen. Habe aber trotzdem noch Umbenennung durchgeführt:
  ````text
  PS C:\Users\User\BsTd\BsDoc\mm-github-starter\bs-mm-doc> git remote -v
  origin  https://github.com/muellerh08/mm-github-starter.git (fetch)
  origin  https://github.com/muellerh08/mm-github-starter.git (push)
  PS C:\Users\User\BsTd\BsDoc\mm-github-starter\bs-mm-doc> git remote set-url origin https://github.com/muellerh08/bs-mm-doc
  PS C:\Users\User\BsTd\BsDoc\mm-github-starter\bs-mm-doc> git remote -v
  origin  https://github.com/muellerh08/bs-mm-doc (fetch)
  origin  https://github.com/muellerh08/bs-mm-doc (push)
  ````

- 01.03.24: Neue Seiten anlegen siehe Step 2: add pages at https://zenglix.github.io/personal_website/
- 08.03.24: bs-mm-doc von ...\BsTd\BsDoc\mm-github-starter\ nach ...\BsTd\BsWb\ verschoben.

## Protokolle

### 240228-1clone

```text
User@Me19 MINGW64 ~/BsTd/BsDoc/mm-github-starter
$ ls -als
total 4
0 drwxr-xr-x 1 User 197608 0 Feb 28 15:53 ./
4 drwxr-xr-x 1 User 197608 0 Feb 28 15:53 ../

User@Me19 MINGW64 ~/BsTd/BsDoc/mm-github-starter
$ git clone https://github.com/muellerh08/mm-github-starter.git
Cloning into 'mm-github-starter'...
remote: Enumerating objects: 26, done.
remote: Counting objects: 100% (26/26), done.
remote: Compressing objects: 100% (21/21), done.
remote: Total 26 (delta 1), reused 22 (delta 1), pack-reused 0
Receiving objects: 100% (26/26), 11.89 KiB | 1.98 MiB/s, done.
Resolving deltas: 100% (1/1), done.

User@Me19 MINGW64 ~/BsTd/BsDoc/mm-github-starter
$ ls -als
total 8
0 drwxr-xr-x 1 User 197608 0 Feb 28 16:08 ./
4 drwxr-xr-x 1 User 197608 0 Feb 28 15:53 ../
4 drwxr-xr-x 1 User 197608 0 Feb 28 16:08 mm-github-starter/

User@Me19 MINGW64 ~/BsTd/BsDoc/mm-github-starter
$ cd mm-github-starter/

User@Me19 MINGW64 ~/BsTd/BsDoc/mm-github-starter/mm-github-starter (master)
$ ls -als
total 23
4 drwxr-xr-x 1 User 197608    0 Feb 28 16:08 ./
0 drwxr-xr-x 1 User 197608    0 Feb 28 16:08 ../
4 drwxr-xr-x 1 User 197608    0 Feb 28 16:08 .git/
1 -rw-r--r-- 1 User 197608   50 Feb 28 16:08 .gitignore
4 -rw-r--r-- 1 User 197608 3254 Feb 28 16:08 _config.yml
0 drwxr-xr-x 1 User 197608    0 Feb 28 16:08 _data/
0 drwxr-xr-x 1 User 197608    0 Feb 28 16:08 _pages/
4 drwxr-xr-x 1 User 197608    0 Feb 28 16:08 _posts/
0 drwxr-xr-x 1 User 197608    0 Feb 28 16:08 assets/
1 -rw-r--r-- 1 User 197608  379 Feb 28 16:08 Gemfile
1 -rw-r--r-- 1 User 197608  241 Feb 28 16:08 index.html
4 -rw-r--r-- 1 User 197608 1394 Feb 28 16:08 README.md

User@Me19 MINGW64 ~/BsTd/BsDoc/mm-github-starter/mm-github-starter (master)
```

### 240228-2serve

```

PS C:\Users\User\BsTd\BsDoc\mm-github-starter\mm-github-starter> bundle
Fetching gem metadata from https://rubygems.org/...........
Resolving dependencies...
Bundle complete! 10 Gemfile dependencies, 106 gems now installed.
Use `bundle info [gemname]` to see where a bundled gem is installed.
PS C:\Users\User\BsTd\BsDoc\mm-github-starter\mm-github-starter> bundle exec jekyll serve
To use retry middleware with Faraday v2.0+, install `faraday-retry` gem
Configuration file: C:/Users/User/BsTd/BsDoc/mm-github-starter/mm-github-starter/_config.yml
            Source: C:/Users/User/BsTd/BsDoc/mm-github-starter/mm-github-starter
       Destination: C:/Users/User/BsTd/BsDoc/mm-github-starter/mm-github-starter/_site
 Incremental build: disabled. Enable with --incremental
      Generating...
      Remote Theme: Using theme mmistakes/minimal-mistakes
       Jekyll Feed: Generating feed for posts
   GitHub Metadata: No GitHub API authentication could be found. Some fields may be missing or have incorrect data.
                    done in 11.732 seconds.
 Auto-regeneration: enabled for 'C:/Users/User/BsTd/BsDoc/mm-github-starter/mm-github-starter'
<internal:C:/Ruby32-x64/lib/ruby/site_ruby/3.2.0/rubygems/core_ext/kernel_require.rb>:37:in `require': cannot load such file -- webrick (LoadError)
```
### 240228-3inServe
````
Use `bundle info [gemname]` to see where a bundled gem is installed.
PS C:\Users\User\BsTd\BsDoc\mm-github-starter\mm-github-starter> bundle install
Fetching gem metadata from https://rubygems.org/.........
Resolving dependencies...
Bundle complete! 11 Gemfile dependencies, 107 gems now installed.
Use `bundle info [gemname]` to see where a bundled gem is installed.
PS C:\Users\User\BsTd\BsDoc\mm-github-starter\mm-github-starter> bundle exec --verbose jekyll serve

To use retry middleware with Faraday v2.0+, install `faraday-retry` gem
Configuration file: C:/Users/User/BsTd/BsDoc/mm-github-starter/mm-github-starter/_config.yml
            Source: C:/Users/User/BsTd/BsDoc/mm-github-starter/mm-github-starter
       Destination: C:/Users/User/BsTd/BsDoc/mm-github-starter/mm-github-starter/_site
 Incremental build: disabled. Enable with --incremental
      Generating...
      Remote Theme: Using theme mmistakes/minimal-mistakes
       Jekyll Feed: Generating feed for posts
                    done in 9.633 seconds.
 Auto-regeneration: enabled for 'C:/Users/User/BsTd/BsDoc/mm-github-starter/mm-github-starter'
    Server address: http://127.0.0.1:4000
  Server running... press ctrl-c to stop.
````
