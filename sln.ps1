$has_include = (Join-Path (Get-Item .).Parent.FullName has_include)
$preprocessor = (Join-Path (Get-Item .).Parent.FullName preprocessor)
cmake -B "build" -G "Visual Studio 16 2019" -A x64 -T v142 -Dhas_include_ROOT="$has_include" -Dpreprocessor_ROOT="$preprocessor"