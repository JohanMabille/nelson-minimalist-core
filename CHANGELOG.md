# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/).

## 0.3.0 (2023-03-30)

### Added

- function handle builtin added:
  `func2str`, `function_handle_extraction`
  `isfunction_handle`, `function_handle_fieldnames`
  `function_handle_isequal`, `function_handle_isequaln`
  `function_handle_isequalto`, `str2func`

- validators builtin added:
  `mustBeNumericOrLogical`, `mustBeLogical`, `mustBeLogicalScalar`,
  `mustBeFinite`, `mustBeScalarOrEmpty`,
  `mustBeValidVariableName`, `mustBeTextScalar`,
  `mustBeText`, `mustBeFolder`,
  `mustBeFile`, `mustBeVector`,
  `mustBeFloat`, `mustBeNumeric`,
  `mustBeNonempty`, `mustBeA`,
  `mustBePositive`, `mustBeNonnegative`,
  `mustBeNegative`, `mustBeNonpositive`,
  `mustBeNonNan`, `mustBeNonZero`,
  `mustBeNonSparse`, `mustBeReal`,
  `mustBeInteger`, `mustBeNonmissing`,
  `mustBeGreaterThan`, `mustBeLessThan`,
  `mustBeGreaterThanOrEqual`, `mustBeLessThanOrEqual`,
  `mustBeMember`, `mustBeInRange`

- files folders builtin added:
  `pwd`, `dir`
  `cd`, `isdir`
  `isfolder`, `isfile`
  `fileparts`, `mkdir`
  `relativepath`, `rmdir`
  `copyfile`, `diff_file`
  `rmfile`, `pathsep`
  `filesep`, `fullpath`
  `tempdir`, `userdir`, `fullfile`

- interpreter builtin added:
  `parsefile`, `parsestring`, `max_recursion_depth`, `iskeyword`

- console builtin added:
  `clc`, `input`, `terminal_size`

- debugger builtin added:
  `dbstack`

- integer builtin added:
  `int8`, `int16`
  `int32`, `int64`
  `uint8`, `uint16`
  `uint32`, `uint64`
  `intmax`, `intmin`

- double builtin added:
  `double`, `flintmax`, `realmax`

- assert_functions builtin added:
  `assert_istrue`, `assert`
  `assert_isfalse`, `assert_checkerror`
  `assert_isequal`, `assert_isapprox`

- operators builtin added:
  `plus`, `minus`,
  `uminus`, `uplus`,
  `and`, `colon`,
  `ctranspose`, `transpose`,
  `eq`, `ge`,
  `gt`, `le`,
  `lt`, `ne`,
  `ldivide`, `rdivide`,
  `mldivide`, `mrdivide`,
  `mtimes`, `times`,
  `not`, `or`,
  `any`, `all`,
  `power`, `mpower`,
  `shortcutor`, `shortcutand`,
  `subsindex`, `horzcat`,
  `vertcat`, `ismember`,

- data_structures builtin added:
  `isfield`, `fieldnames`, `cellfun`,
  `namedargs2cell`, `getfield`,
  `rmfield`, `struct`,
  `iscellstr`, `cell`,
  `struct2cell`, `cell2struct`

- functions_manager builtin added:
  `macroargs`, `builtin`,
  `feval`, `what`,
  `addpath`, `clearfun`,
  `rmpath`, `path`,
  `ismacro`, `isbuiltin`,
  `rehash`, `userpath`, `inmem`

- memory_manager builtin added:
  `clear`, `who`
  `whos`, `global`
  `isglobal`, `persistent`
  `assignin`, `acquirevar`
  `varlock`, `varunlock`
  `varislock`, `isvar`

- error_manager builtin added:
  `error`, `warning`
  `lasterror`, `lastwarn`
  `getLastReport`, `MException`
  `throw`, `throwAsCaller`
  `rethrow`, `MException_fieldnames`

- core builtin added:
  `exit`, `run`
  `nfilename`, `mfilename`
  `execstr`, `eval`
  `evalc`, `evalin`
  `nargin`, `narginchk`
  `nargout`, `nargoutchk`
  `pause`, `namelengthmax`, `inputname`

- logical builtin added:
  `logical`, `true`,
  `false`, `"xor`,

- single builtin added:
  `single`

- data_analysis builtin added:
  `prod`, `sum`, `cumsum`,
  `cumprod`, `ismissing`,
  `sort`, `max`,
  `min`, `conv2`

- statistics builtin added:
  `corrcoef`, `var`, `mean`

- stream_manager builtin added:
  `diary`, `fopen`,
  `fclose`, `fwrite`,
  `fread`, `fprintf`,
  `fgetl`, `fgets`,
  `ftell`, `frewind`,
  `fseek`, `fsize`,
  `dlmwrite`, `fileread`,
  `filewrite`, `feof`,
  `ferror`, `fscanf`,
  `sscanf`

- string builtin added:
  `char`, `strcmp`,
  `strcmpi`, `strncmp`,
  `strncmpi`, `matches`,
  `tolower`, `lower`,
  `toupper`, `upper`,
  `strfind`, `int2str`,
  `num2str`, `str2double`,
  `mat2str`, `startsWith`,
  `endsWith`, `contains`,
  `count`, `strrep`,
  `replace`, `strtrim`,
  `deblank`, `strlength`,
  `string`, `strings`,
  `convertStringsToChars`, `convertCharsToStrings`,
  `blanks`, `strcat`,
  `append`, `isletter`

- time builtin added:
  `tic`, `toc`,
  `sleep`, `datevec`,
  `timeit`

- constructors_function builtin added:
  `eye`, `i`,
  `j`, `nan`,
  `NaN`, `inf`,
  `Inf`, `eps`,
  `pi`, `ones`,
  `zeros`, `diag`

- linear_algebra builtin added:
  `sqrtm`, `logm`,
  `expm`,, `schur`,
  `trace`, `issymmetric`,
  `ishermitian`, `det`

- elementary_functions builtin added:
  `size`, `length`, `reshape`, `real`
  `imag`, `complex`, `isequal`, `isequaln`
  `isequalto`, `numel`, `isapprox`, `ceil`
  `floor`, `fix`, `round`, `isnan`
  `isinf`, `isfinite`, `ndims`, `conj`
  `mod`, `abs`, `repmat`, `rem`
  `cast`, `norm`, `exp`, `log`
  `log10`, `log1p`, `sqrt`, `num2bin`
  `bin2num`, `base2dec`, `bin2dec`
  `hex2dec`, `dec2base`, `dec2bin`, `dec2hex`
  `linspace`, `log2`, `fliplr`, `flipud`
  `find`, `isvector`, `isscalar`, `triu`
  `tril`, `sign`, `hypot`, `permute`

- types module builtin added:
  `class`, `isa`, `iscell`, `ischar`
  `isclass`, `isdouble`, `isempty`, `isfloat`
  `ishandle`, `isint8`, `isint16`, `isint32`
  `isint64`, `isinteger`, `islogical`, `isnumeric`
  `isreal`, `issingle`, `issparse`, `isstring`
  `isuint8`, `isuint16`, `isuint32`, `isuint64`
  `isvarname`

- [#48](https://github.com/Nelson-numerical-software/nelson-minimalist-core/issues/48): Add static build to CI.
- [#6](https://github.com/Nelson-numerical-software/nelson-minimalist-core/issues/6): Windows build with cmake.
- [#24](https://github.com/Nelson-numerical-software/nelson-minimalist-core/issues/24): CI build with Cmake on Windows.
- [#17](https://github.com/Nelson-numerical-software/nelson-minimalist-core/issues/17): Add minimal tests to the CI.
- plug `trigonometric_functions` module (currently only builtin)
  `cos`, `sin`, `tan`, `cosh`, `sinh`, `tanh`, `acos`, `asin`, `atan`, `cosm`, `sinm`, `tanm`, `atan2`, `atanh`
- plug `display_format` module (format, disp, display, echo)
- builtin loaded by gateway.

### Fixed

- [#47](https://github.com/Nelson-numerical-software/nelson-minimalist-core/issues/47): Duplicate symbols errors when building nelson-minimalist-core on emscripten-forge.

## 0.1.0

### Added

- [#16](https://github.com/Nelson-numerical-software/nelson-minimalist-core/issues/16): text_completion code imported.

- [#13](https://github.com/Nelson-numerical-software/nelson-minimalist-core/issues/13): cmake packaging (Thanks to JohanMabille).

- [#11](https://github.com/Nelson-numerical-software/nelson-minimalist-core/issues/11): plug 'addpath' builtin.

### Changed

- nelson.sln renamed to nelson-minimalist-core.sln

- synchronized with complete version Nelson 0.6.12

### Fixed

- [#23](https://github.com/Nelson-numerical-software/nelson-minimalist-core/issues/23): VariableCompleter was not filtered by prefix.

- [#8](https://github.com/Nelson-numerical-software/nelson-minimalist-core/issues/8): Install nelson-minimalist-core in local environment

Thanks to JohanMabille, Hind-M and [QuantStack](https://quantstack.net/) for their helps for this initial version of nelson-minimalist-core.
