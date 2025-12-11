#!/bin/sh

if ! [ -e 'gui' ]; then
    echo 'Wrong path!'
    exit 1
fi

mkdir -p gui/lib

if [ -z "$(ls -A gui/lib)" ]; then
    echo 'gui/lib/htm.js ...'
    curl -L -o gui/lib/htm.js -s https://unpkg.com/htm/dist/htm.module.js

    echo 'gui/lib/preact.js ...'
    curl -L -o gui/lib/preact.js -s https://unpkg.com/preact/dist/preact.module.js

    echo 'gui/lib/tailwindcss.js ...'
    curl -L -o gui/lib/tailwindcss.js -s https://cdn.jsdelivr.net/npm/@tailwindcss/browser@4

    echo 'gui/lib/hooks.js ...'
    curl -L -o gui/lib/hooks.js -s https://unpkg.com/preact/hooks/dist/hooks.module.js
    sed -i 's/"preact"/".\/preact.js"/g' gui/lib/hooks.js

    echo 'gui/lib/signals-core.js ...'
    curl -L -o gui/lib/signals-core.js -s https://unpkg.com/@preact/signals-core/dist/signals-core.module.js

    echo 'gui/lib/signals.js ...'
    curl -L -o gui/lib/signals.js -s https://unpkg.com/@preact/signals/dist/signals.module.js
    sed -i 's|"preact"|"./preact.js"|g' gui/lib/signals.js
    sed -i 's|"preact/hooks"|"./hooks.js"|g' gui/lib/signals.js
    sed -i 's|"@preact/signals-core"|"./signals-core.js"|g' gui/lib/signals.js
else
    exit 0
fi
