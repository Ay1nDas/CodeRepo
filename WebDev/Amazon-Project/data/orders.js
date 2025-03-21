export const orders = JSON.parse(localStorage.getItem('storage')) || [];

export function saveOrder(order) {
  orders.unshift(order);
  saveToStorage();
  console.log(orders);
}

function saveToStorage() {
  localStorage.setItem('orders', JSON.stringify(orders));
}
