import { cart, totalCartItem } from '../../data/cart.js';
import { products, getProduct } from '../../data/products.js';
import { getDeliveryOption } from '../../data/delivery.js';
import { formatCurrency } from '../utils/money.js';
import { saveOrder } from '../../data/orders.js';

export function renderPaymentSummary() {
  let cartPriceCents = 0;
  let shippingPriceCents = 0;

  cart.forEach((cartItem) => {
    const product = getProduct(cartItem.productID);
    // console.log(product);
    cartPriceCents += product.priceCents * cartItem.quantity;

    const delivery = getDeliveryOption(cartItem.deliveryId);
    shippingPriceCents += delivery.chargeCents;
  });
  // console.log(cartPriceCents);
  // console.log(shippingPriceCents);

  const totalCentsBeforeTax = cartPriceCents + shippingPriceCents;
  const taxCents = totalCentsBeforeTax * 0.1;
  const OrderTotalCents = totalCentsBeforeTax + taxCents;

  const paymentSummaryHTML = `
    <div class="payment-summary-title">Order Summary</div>

    <div class="payment-summary-row">
      <div>Items (${totalCartItem}):</div>
      <div class="payment-summary-money">
        $${formatCurrency(cartPriceCents)}
      </div>
    </div>

    <div class="payment-summary-row">
      <div>Shipping &amp; handling:</div>
      <div class="payment-summary-money">
      $${formatCurrency(shippingPriceCents)}
      </div>
    </div>

    <div class="payment-summary-row subtotal-row">
      <div>Total before tax:</div>
      <div class="payment-summary-money">
      $${formatCurrency(totalCentsBeforeTax)}
      </div>
    </div>

    <div class="payment-summary-row">
      <div>Estimated tax (10%):</div>
      <div class="payment-summary-money">
      $${formatCurrency(taxCents)}
      </div>
    </div>

    <div class="payment-summary-row total-row">
      <div>Order total:</div>
      <div class="payment-summary-money">
      $${formatCurrency(OrderTotalCents)}
      </div>
    </div>

    <button class="place-order-button button-primary js-order-btn">
      Place your order
    </button>
  `;

  document.querySelector('.js-payment-summary').innerHTML = paymentSummaryHTML;

  document
    .querySelector('.js-order-btn')
    .addEventListener('click', async () => {
      try {
        const response = await fetch('https://supersimplebackend.dev/orders', {
          method: 'POST',
          headers: {
            'Content-Type': 'application/json',
          },
          body: JSON.stringify({
            cart: cart,
          }),
        });
        const order = await json.response;
        saveOrder(order);
      } catch (error) {
        alert(error);
      }
    });
}
