// @ts-check
import { html } from "./lib.js";

export const input = {
  content: "default",
  visible: true,
};

export function Input() {
  return html`
    <p class="grid place-self-center text-white underline">
      ${input.visible && input.content}
    </p>
  `;
}
