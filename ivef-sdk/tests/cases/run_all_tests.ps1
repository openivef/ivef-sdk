param(
    [Parameter(Mandatory=$true)]
    [ValidateSet("qt", "objc", "java", "php", "all")]
    [string]$Mode
)

# Directories
$DATADIR = "data"
$TMPDIR  = "tmp"

# Resolve command based on selected mode
switch ($Mode) {
    "qt" {
        $env:PATH = "$env:GITHUB_WORKSPACE\ivef-sdk\build/targets/qt/lib;$env:PATH"
        $COMMAND_EXE = "../qt/bin/testqt.exe"
        $COMMAND_ARGS = @()
        if (!(Test-Path $COMMAND_EXE)) {
            Write-Error "test program not found at $COMMAND_EXE"
            exit 1
        }
    }

    "objc" {
        $COMMAND_EXE = "../objc/build/Release/testobjc"
        $COMMAND_ARGS = @()
        if (!(Test-Path $COMMAND_EXE)) {
            Write-Error "test program not found at $COMMAND_EXE"
            exit 1
        }
    }

    "java" {
        $COMMAND_EXE = "java"
        $COMMAND_ARGS = @("-classpath", "../java/target/testjava.jar;../../build/targets/java/ivef/ivef.jar", "testjava/testjava")
    }

    "php" {
        $COMMAND_ARGS = @("../php/test.php")
        # Try php5 then php
        if (Get-Command php5 -ErrorAction SilentlyContinue) {
            $COMMAND_EXE = "php5"
        }
        elseif (Get-Command php -ErrorAction SilentlyContinue) {
            $COMMAND_EXE = "php"
        }
        else {
            Write-Error "php executable not found"
            exit 1
        }
    }

    "all" {
        pwsh ./run_all_tests.ps1 php
        if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
        pwsh ./run_all_tests.ps1 qt
        if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
        pwsh ./run_all_tests.ps1 objc
        if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
        pwsh ./run_all_tests.ps1 java
        if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
        exit 0
    }
}

# Prepare temp directory
if (!(Test-Path $TMPDIR)) { New-Item -ItemType Directory -Path $TMPDIR | Out-Null }
Get-ChildItem $TMPDIR | Remove-Item -Recurse -Force

# Gather input files (*.xml.in and *.xml-$Mode.in)
$inputFiles = @()
$inputFiles += Get-ChildItem "$DATADIR/*.xml.in" -ErrorAction SilentlyContinue

foreach ($file in $inputFiles) {

    $inputPath = $file.FullName
    $baseName = $file.BaseName
    $relativeName = $file.Name

    # Determine expected output filename <something>-<mode>.out or fallback
    $OUTNAME = ($relativeName -replace '\.xml.in$', '') + ".xml-$Mode.out"

    if (!(Test-Path "$DATADIR/$OUTNAME")) {
        # Fallback to .out without mode
        $OUTNAME = ($relativeName -replace '\.xml\.in$', '') + ".xml.out"

        if (!(Test-Path "$DATADIR/$OUTNAME")) {
            Write-Host "ERROR: No reference file exists for: $DATADIR/$OUTNAME"
            exit 1
        }
    }

    Write-Host "running test $baseName : $relativeName -> $OUTNAME ...... "

    # Run test
    Write-Host -ForegroundColor Yellow "RUN 1"
    $outputFile = "$TMPDIR/$OUTNAME"
    Get-Content $inputPath -Encoding UTF8 | & $COMMAND_EXE @COMMAND_ARGS | Out-File -Encoding UTF8 $outputFile

    # Handle null cases explicitly
    if ($null -eq (Get-Content -Encoding UTF8 "$outputFile")) {
        Write-Host "NOK"
        Write-Host "---"
        Write-Host "ERROR: Output file is empty or unreadable: $outputFile"
        Write-Host "---"
        Write-Host (Get-Content -Encoding UTF8 "$outputFile")
        Write-Host "---"
        exit 1
    }

    # Compare ignoring whitespace (-w)
    $diff = Compare-Object `
        (Get-Content -Encoding UTF8 "$DATADIR/$OUTNAME") `
        (Get-Content -Encoding UTF8 "$outputFile")

    if ($diff.Count -eq 0) {
        Write-Host "OK"
    }
    else {
        Write-Host "NOK"
        Write-Host "---"
        Write-Host "Difference: $outputFile  data/$OUTNAME"
        Write-Host "---"

        # Side-by-side diff equivalent
        # PowerShell does not have sdiff, but we can approximate:
        $left  = Get-Content $outputFile
        $right = Get-Content "$DATADIR/$OUTNAME"

        for ($i = 0; $i -lt [Math]::Max($left.Count, $right.Count); $i++) {
            "{0,-60} | {1}" -f $left[$i], $right[$i]
        }

        Write-Host "---"
        exit 1
    }
}

# Clean up
Remove-Item -Recurse -Force $TMPDIR
