# calc


[![CircleCI](https://circleci.com/gh/yourgithubhandle/calc/tree/master.svg?style=svg)](https://circleci.com/gh/yourgithubhandle/calc/tree/master)


**Contains the following libraries and executables:**

```
calc@0.0.0
│
├─test/
│   name:    TestCalc.exe
│   main:    TestCalc
│   require: calc.lib
│
├─library/
│   library name: calc.lib
│   namespace:    Calc
│   require:
│
└─executable/
    name:    CalcApp.exe
    main:    CalcApp
    require: calc.lib
```

## Developing:

```
npm install -g esy
git clone <this-repo>
esy install
esy build
```

## Running Binary:

After building the project, you can run the main binary that is produced.

```
esy x CalcApp.exe 
```

## Running Tests:

```
# Runs the "test" command in `package.json`.
esy test
```
