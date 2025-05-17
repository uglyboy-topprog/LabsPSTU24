from deep_translator import GoogleTranslator
import sys
import io

# Устанавливаем кодировку для вывода
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8')

def translate_text(text):
    try:
        translated = GoogleTranslator(source='en', target='ru').translate(text)
        return translated
    except Exception as e:
        return f"Ошибка перевода: {str(e)}"

if __name__ == "__main__":
    text = sys.argv[1] if len(sys.argv) > 1 else ""
    if text:
        print(translate_text(text))
    else:
        print("Ошибка: текст не передан.")
