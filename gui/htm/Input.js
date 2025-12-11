// @ts-check
import { html, signal } from "../lib.js";

/** @type import("../lib.js").Signal<string[]> */
const inputList = signal(["default-0", "default-1"]);

/**
 * @param {string} input
 */
export function pushInput(input) {
  inputList.value = [...inputList.value, input].slice(-15);
}

/** @type import("../lib.js").Signal<boolean> */
export const visible = signal(true);

export function Input() {
  return html`
    <p class="grid place-self-center text-white underline">
      ${visible.value &&
        inputList.value.map(
          (input) =>
            html`
              <div>${input}</div>
            `,
        )}
    </p>
  `;
}
