# Espresso ☕️

This is the Espresso with version 2.3 extracted from the SIS repo archived [here](https://github.com/berkeley-abc/sis), and it is still WIP.
<br/>SIS contains a lot of stuff and is quite hard to compile using the SOTA compiler, so I extract the espresso here to do a separate archive.

## Note
This is important, although examples can successfully run, since I pruned a lot of dependencies such as `st` and `mm` in `utility`, so there's no regression test, good luck.
<br/><em>I will add them back in the future if I have time, feel free to drop a PR here.</em>
The `Makefile` is a mess now, refactor is welcome.

## How to build
This version has been compiled on macOS with clang version
```
Apple clang version 15.0.0 (clang-1500.3.9.4)
Target: arm64-apple-darwin23.6.0
Thread model: posix
```
There are still lots of warning due to the ancient style of the code, I add an option for suppressing them. Make with `CDBG=-w` will do:
```
make CDBG=-w
```
and clean with
```
make clean
```

## Run example
`cd` to the example folder and type `make`.

## Help page
```
UC Berkeley, Espresso Version #2.3, Release date 01/31/88

SYNOPSIS: espresso [options] [file]

  -d        Enable debugging
  -e[opt]   Select espresso option:
                fast, ness, nirr, nunwrap, onset, pos, strong,
                eat, eatdots, kiss, random
  -o[type]  Select output format:
                f, fd, fr, fdr, pleasure, eqntott, kiss, cons
  -rn-m     Select range for subcommands:
                d1merge: first and last variables (0 ... m-1)
                minterms: first and last variables (0 ... m-1)
                opoall: first and last outputs (0 ... m-1)
  -s        Provide short execution summary
  -t        Provide longer execution trace
  -x        Suppress printing of solution
  -v[type]  Verbose debugging detail (-v '' for all)
  -D[cmd]   Execute subcommand 'cmd':
                ESPRESSO, many, exact, qm, single_output, so, so_both,
                simplify, echo, opo, opoall, pair, pairall, check, stats,
                verify, PLAverify, equiv, map, mapdc, fsm, contain, d1merge,
                d1merge_in, disjoint, dsharp, intersect, minterms, primes,
                separate, sharp, union, xor, essen, expand, gasp, irred,
                make_sparse, reduce, taut, super_gasp, lexsort, test
  -Sn       Select strategy for subcommands:
                opo: bit2=exact bit1=repeated bit0=skip sparse
                opoall: 0=minimize, 1=exact
                pair: 0=algebraic, 1=strongd, 2=espresso, 3=exact
                pairall: 0=minimize, 1=exact, 2=opo
                so_espresso: 0=minimize, 1=exact
                so_both: 0=minimize, 1=exact
```
