#!/bin/sh

if ! [ -e "./gui" ]; then
    echo 'Wrong path!'
    exit 1
fi

mkdir -p ./gui/lib

if [ -z "$(ls -A ./gui/lib)" ]; then
    echo './gui/lib/htm.js ...'
    curl -L -o ./gui/lib/htm.js -s https://unpkg.com/htm/dist/htm.module.js
    echo './gui/lib/preact.js ...'
    curl -L -o ./gui/lib/preact.js -s https://unpkg.com/preact/dist/preact.module.js
    echo './gui/lib/tailwindcss.js ...'
    curl -L -o ./gui/lib/tailwindcss.js -s https://cdn.jsdelivr.net/npm/@tailwindcss/browser@4
else
    exit 0
fi
