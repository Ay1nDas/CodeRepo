import { renderCheckoutCart } from './checkout/orders.js';
import { renderPaymentSummary } from './checkout/payment.js';
import { loadProducts } from '../data/products.js';

loadProducts(renderPage);

export function renderPage() {
  renderCheckoutCart();
  renderPaymentSummary();
}
