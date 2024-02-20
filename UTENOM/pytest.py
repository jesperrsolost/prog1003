import requests
import openpyxl
import time

# Buff.163 API URL for the item you want to track (replace with your specific item ID)
ITEM_ID = 33870  # Example item ID

# Excel file path
EXCEL_FILE = 'C:/Users/jespe/Downloads/buffapi.xlsx'

def get_buff163_price():
    try:
        url = f"https://buff.163.com/api/market/goods/buy_order?game=csgo&goods_id={ITEM_ID}&page_num=1"
        response = requests.get(url)
        data = response.json()
        lowest_price = data['data']['items'][0]['price']
        return lowest_price
    except Exception as e:
        print(f"Error fetching Buff.163 price: {e}")
        return None

def update_excel_cell(price):
    try:
        wb = openpyxl.load_workbook(EXCEL_FILE)
        sheet = wb.active
        cell = sheet['A1']  # Replace with the desired cell (e.g., 'B2')
        cell.value = price
        wb.save(EXCEL_FILE)
        print(f"Updated Excel cell with price: {price}")
    except Exception as e:
        print(f"Error updating Excel cell: {e}")

def main():
    while True:
        price = get_buff163_price()
        if price is not None:
            update_excel_cell(price)
        time.sleep(3600)  # Wait for an hour before checking again

if __name__ == "__main__":
    main()
