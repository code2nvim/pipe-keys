// @ts-check
import { html } from "./lib.js";
import { signal } from "./lib/signals.js";

/** @type {{ value: string[] }} */
const inputList = signal(["default-0", "default-1"]);

/**
 * @param {string} input
 */
export function pushInput(input) {
  inputList.value = [...inputList.value, input].slice(-15);
}

/** @type {{ value: boolean }} */
export const visible = signal(true);

export function Input() {
  return html`
    <p class="grid place-self-center text-white underline">
      ${visible.value &&
        inputList.value.map(
          (/** @type {string} */ input) =>
            html`
              <div>${input}</div>
            `,
        )}
    </p>
  `;
}
