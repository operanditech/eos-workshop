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

## Building

### Contract

To build the contract, you will need to run this command:

```
eosio-cpp -abigen -contract=coolstorybro contract/coolstorybro.cpp -o contract/coolstorybro.wasm
```

This will generate the WASM file and the ABI file, which you need to
deploy to the blockchain.

### Frontend

To run the frontend, you will need to first install its dependencies:

```
cd frontend
npm install
```

Then, run the development server and open the site in your browser:

```
npm run serve
```

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

You can also add a VSCode task to build the contract
more easily. Add the following task definition
to your `.vscode/tasks.json`:

```json
{
  "label": "Build contract",
  "type": "shell",
  "command": "eosio-cpp -abigen -contract=coolstorybro contract/coolstorybro.cpp -o contract/coolstorybro.wasm",
  "group": {
    "kind": "build",
    "isDefault": true
  }
}
```
