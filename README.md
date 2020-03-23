# testbuilder

Testbuilder generates fuzz tests using google/gofuzz based on annotations added to the Go source code.
It can be used to instrument
* struct recievers
* functions

That accept

* basic types
* pointer-to-object
* slices

as arguments. It could be extended to take more types.

Note that you should offer concrete types in the annotations, and there can be more than one annotation
per function. Nor must they be in any particular location.

### Usage

`./testbuilder path/to/package > redirected_stdin_test.go`

Some things to note:
* testbuilder will take the last bit of `path/to/package` as the package name
	* testbuilder does dot expansion
* testbuilder parses all files in a package directory that
	* have the extension `.go`
	* AND do not end in the suffix `_test.go`. You should therefore name your fuzz test files
	with the suffix `_test.go`.

### Annotation Grammar for testbuilder

```
//testbuilder: FUNC_IDENT [on_type IDENT] args: [TYPE[ ...]]
```
Look at [example_pkg](https://github.com/ClaytonMcCray/example_pkg) for concrete annotation examples.

