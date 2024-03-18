---
title: "Surge"
layout: single
permalink: /docs/surge/
comments: true
sidebar:
  nav: doc_nav
toc: true  
---
## Surge-Installation

- 17.03.24: Nach [Getting started with Surge](https://surge.sh/help/getting-started-with-surge), bzw.
[Deploying a Jekyll project](https://surge.sh/help/deploying-a-jekyll-project) surge installiert, siehe [240317-1inst](#240317-1inst).
- Das erste Deployment, siehe [240317-2depl](#240317-2depl).
- [How to update your surge.sh project?](https://stackoverflow.com/questions/49243509/how-to-update-your-surge-sh-project)
- [Remembering a domain](https://surge.sh/help/remembering-a-domain)

## Protokolle

### 240317-1inst

````text
PS C:\Users\User\BsTd\BsDoc\HelloWorld> npm install --global surge
npm WARN deprecated har-validator@5.1.5: this library is no longer supported
npm WARN deprecated uuid@3.4.0: Please upgrade  to version 7 or higher.  Older versions may use Math.random() in certain circumstances, which is known to be problematic.  See https://v8.dev/blog/math-random for details.
npm WARN deprecated request@2.88.2: request has been deprecated, see https://github.com/request/request/issues/3142

added 112 packages in 13s

4 packages are looking for funding
  run `npm fund` for details
npm notice
npm notice New minor version of npm available! 10.4.0 -> 10.5.0
npm notice Changelog: https://github.com/npm/cli/releases/tag/v10.5.0
npm notice Run npm install -g npm@10.5.0 to update!
npm notice

PS C:\Users\User\BsTd\BsDoc\HelloWorld> npm install -g npm@10.5.0

removed 1 package, and changed 36 packages in 7s

24 packages are looking for funding
  run `npm fund` for details
````  

### 240317-2depl

````text
PS C:\Users\User\BsTd\BsWb\bs-mm> jekyll build
C:/Ruby32-x64/lib/ruby/site_ruby/3.2.0/bundler/runtime.rb:304:in `check_for_activated_spec!': You have already activated jekyll-sass-converter 3.0.0, but your Gemfile requires jekyll-sass-converter 1.5.2. Prepending `bundle exec` to your command may solve this. (Gem::LoadError)
        from C:/Ruby32-x64/lib/ruby/site_ruby/3.2.0/bundler/runtime.rb:25:in `block in setup'
        from C:/Ruby32-x64/lib/ruby/site_ruby/3.2.0/bundler/spec_set.rb:191:in `each'
        from C:/Ruby32-x64/lib/ruby/site_ruby/3.2.0/bundler/spec_set.rb:191:in `each'
        from C:/Ruby32-x64/lib/ruby/site_ruby/3.2.0/bundler/runtime.rb:24:in `map'
        from C:/Ruby32-x64/lib/ruby/site_ruby/3.2.0/bundler/runtime.rb:24:in `setup'
        from C:/Ruby32-x64/lib/ruby/site_ruby/3.2.0/bundler.rb:162:in `setup'
        from C:/Ruby32-x64/lib/ruby/gems/3.2.0/gems/jekyll-4.3.3/lib/jekyll/plugin_manager.rb:52:in `require_from_bundler'
        from C:/Ruby32-x64/lib/ruby/gems/3.2.0/gems/jekyll-4.3.3/exe/jekyll:11:in `<top (required)>'
        from C:/Ruby32-x64/bin/jekyll:25:in `load'
        from C:/Ruby32-x64/bin/jekyll:25:in `<main>'
PS C:\Users\User\BsTd\BsWb\bs-mm> bundle exec jekyll build
Configuration file: C:/Users/User/BsTd/BsWb/bs-mm/_config.yml
            Source: C:/Users/User/BsTd/BsWb/bs-mm
       Destination: C:/Users/User/BsTd/BsWb/bs-mm/_site
 Incremental build: disabled. Enable with --incremental
      Generating...
      Remote Theme: Using theme root-project/minimal-mistakes
       Jekyll Feed: Generating feed for posts
                    done in 24.344 seconds.
 Auto-regeneration: disabled. Use --watch to enable.
PS C:\Users\User\BsTd\BsWb\bs-mm> surge _site/

   Running as muellerh08@gmail.com (Student)

        project: _site/
         domain: bs-mm.surge.sh
         upload: [=================] 100% eta: 0.0s (1762 files, 16515213 bytes)
            CDN: [====================] 100%
     encryption: *.surge.sh, surge.sh (63 days)
             IP: 138.197.235.123

   Success! - Published to bs-mm.surge.sh
````
