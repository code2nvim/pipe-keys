// @ts-check

/// <reference lib="dom" />
import { Input } from "./Input.js";
import { html } from "./lib.js";
import { render } from "./lib/preact.js";
import { Toggle } from "./Toggle.js";

export function App() {
  return html`
    <div class="absolute grid size-full bg-black">
      <${Input} />
      <${Toggle} />
    </div>
  `;
}

render(
  html`
    <${App} />
  `,
  document.getElementById("app"),
);
