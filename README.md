# Cool Story Bro

> An EOSIO development workshop by @andresberrios

## Required software

- Node.js (`nvm` recommended to install and manage versions)
- Docker. Pull the images for `eos` y `eosio.cdt` with
  `docker pull eosio/cdt` and `docker pull eosio/eos-dev`
- Alternatively, if you are on Mac or Linux, you can install the
  binaries directly:
  - EOS: https://github.com/EOSIO/eos#mac-os-x-brew-install
  - EOSIO.CDT: https://github.com/EOSIO/eosio.cdt#binary-releases

## Configuration

For working on the code, Visual Studio Code is recommended.
You should install the C/C++ extension.
You can configure it to detect the EOSIO libraries by
adding their location to your include path in your `settings.json` like this:

```json
"C_Cpp.default.includePath": [
    "/usr/local/Cellar/eosio.cdt/1.3.2/opt/eosio.cdt/include"
  ]
```
