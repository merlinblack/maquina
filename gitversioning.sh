#!/bin/bash

VERSION=$(git describe 2>/dev/null)

if [ $? -eq 128 ]; then
    VERSION=$(git describe --all 2>/dev/null)

    if [ $? -eq 128 ]; then
        VERSION="Could not get repository revision information."
    fi
fi

echo "Git Versioning Using: $VERSION"

TEMP=$(mktemp GitVersioning.XXXXXX) || exit
trap "rm -f -- '$TEMP'" EXIT

cat > $TEMP << ENDOFDOC
// Git Versioning header.
// Do not edit - auto generated by gitversioning.sh

#define GIT_REPO_REVISION "$VERSION"
ENDOFDOC

# Only touch the header file if the result is different, to avoid
# a needless recompilation.

diff $TEMP gitversioning.h &> /dev/null
if [ $? -gt 0 ]; then
    cp $TEMP gitversioning.h
fi

rm -f -- "$TEMP"
trap - EXIT
exit