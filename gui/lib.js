// @ts-check
import htm from "./lib/htm.js";
import { h, render } from "./lib/preact.js";

export const html = htm.bind(h);

/**
 * @param {Function} Component
 */
export function identify(Component) {
  // FooBar -> foo-bar
  const id = Component.name
    .replace(/([a-z0-9])([A-Z])/g, "$1-$2")
    .replace(/([A-Z])([A-Z][a-z])/g, "$1-$2")
    .toLowerCase();

  return html`
    <div id="${id}" class="contents"><${Component} /></div>
  `;
}

/**
 * @param {Function} Component
 */
export function update(Component) {
  // FooBar -> foo-bar
  const id = Component.name
    .replace(/([a-z0-9])([A-Z])/g, "$1-$2")
    .replace(/([A-Z])([A-Z][a-z])/g, "$1-$2")
    .toLowerCase();

  render(
    html`
      <${Component} />
    `,
    document.getElementById(id),
  );
}
