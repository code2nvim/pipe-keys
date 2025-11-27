// @ts-check
import { Input } from "./Input.js";
import { html, identify, update } from "./lib.js";
import { Toggle } from "./Toggle.js";

export function App() {
  return html`
    <div class="absolute grid size-full bg-black">
      ${identify(Input)}<!--fmt-->
      ${identify(Toggle)}<!--fmt-->
    </div>
  `;
}

update(App);
