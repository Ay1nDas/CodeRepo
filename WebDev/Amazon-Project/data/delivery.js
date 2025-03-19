import dayjs from 'https://unpkg.com/dayjs@1.11.10/esm/index.js';
import { formatCurrency } from '../scripts/utils/money.js';

export const deliveryOptions = [
  {
    id: '1',
    days: 7,
    chargeCents: 0,
  },
  {
    id: '2',
    days: 3,
    chargeCents: 499,
  },
  {
    id: '3',
    days: 1,
    chargeCents: 999,
  },
];

export function getDeliveryOption(deliveryId) {
  let requiredDeliveryOption;
  deliveryOptions.forEach((element) => {
    if (element.id === deliveryId) {
      requiredDeliveryOption = element;
      return;
    }
  });
  return requiredDeliveryOption || deliveryOptions[0];
  // return requiredDeliveryOption;
}

export function generateDelivery(productId, deliveryId, index) {
  let deliveryHTML = ``;

  const today = dayjs();
  deliveryOptions.forEach((delOpt) => {
    const deliveryDate = today.add(delOpt.days, 'days').format('dddd, MMMM D');
    const deliveryPrice = delOpt.chargeCents
      ? `$${formatCurrency(delOpt.chargeCents)} -`
      : 'FREE';

    deliveryHTML += `
      <div class="delivery-option js-delivery-option" 
      data-delivery-id = "${delOpt.id}" 
      data-product-id = "${productId}">
        <input
          type="radio"
          ${delOpt.id === deliveryId ? 'checked' : ''}
          class="delivery-option-input"
          name="delivery-option-${index}"
        />
        <div>
          <div class="delivery-option-date">${deliveryDate}</div>
          <div class="delivery-option-price">${deliveryPrice} Shipping</div>
        </div>
      </div>
    `;
  });

  return deliveryHTML;
}
