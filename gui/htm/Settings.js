// @ts-check
import { html, signal } from "../lib.js";
import { showInput } from "./Input.js";

/** @type {import("../lib.js").Signal<boolean>} */
export const showSettings = signal(false);

export function Settings() {
  return html`
    ${showSettings.value &&
      html`
        <button
          onClick="${() => (showInput.value = !showInput.value)}"
          class="absolute size-1/8 bg-black/50 p-1 text-white"
        >
          ${showInput.value ? "visible" : "hidden"}
        </button>
      `}
  `;
}
