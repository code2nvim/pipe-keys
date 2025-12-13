// @ts-check

/// <reference lib="dom" />
import { html, render } from "../lib.js";
import { Input } from "./Input.js";
import { Settings, showSettings } from "./Settings.js";

export function App() {
  const mouseEnter = () => (showSettings.value = true);
  const mouseLeave = () => (showSettings.value = false);

  return html`
    <div
      onMouseEnter="${mouseEnter}"
      onMouseLeave="${mouseLeave}"
      class="absolute flex size-full bg-black"
    >
      <${Input} />
      <${Settings} />
    </div>
  `;
}

render(
  html`
    <${App} />
  `,
  document.getElementById("app"),
);
