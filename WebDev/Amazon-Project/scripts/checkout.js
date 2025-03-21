import { renderCheckoutCart } from './checkout/orders.js';
import { renderPaymentSummary } from './checkout/payment.js';
import { loadProductsFetch } from '../data/products.js';

async function loadPage() {
  try {
    await loadProductsFetch();
  } catch (error) {
    document.body.innerHTML = `
    <h1>ERROR 404. Couldn't Load the Page.</h1>
    `;
  }
  renderPage();
}
loadPage();

// loadProductsFetch().then(() => {
//   console.log('rendering Page');
//   renderPage();
// });

export function renderPage() {
  renderCheckoutCart();
  renderPaymentSummary();
}
