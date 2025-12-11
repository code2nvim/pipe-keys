// @ts-check
import { visible } from "./Input.js";
import { html } from "./lib.js";

export function Toggle() {
  const handleClick = () => (visible.value = !visible.value);

  return html`
    <button onClick="${handleClick}" class="absolute size-1/8 border text-white">
      ${visible.value ? "visible" : "hidden"}
    </button>
  `;
}
