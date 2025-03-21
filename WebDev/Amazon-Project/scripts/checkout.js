import { renderCheckoutCart } from './checkout/orders.js';
import { renderPaymentSummary } from './checkout/payment.js';
import { loadProducts, loadProductsFetch } from '../data/products.js';

loadProductsFetch().then(() => {
  console.log('rendering Page');
  renderPage();
});

export function renderPage() {
  renderCheckoutCart();
  renderPaymentSummary();
}
