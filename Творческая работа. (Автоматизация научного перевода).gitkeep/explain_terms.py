import json
import sys
import io
import re

# Устанавливаем кодировку для вывода
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8')

def explain_terms(text):
    with open('terms.json', 'r', encoding='utf-8') as f:
        terms_dict = json.load(f)
    
    explanations = []
    # Нормализация текста: убираем знаки препинания и приводим к нижнему регистру
    normalized_text = re.sub(r'[^\w\s]', '', text.lower())
    words = normalized_text.split()
    
    for word in words:
        # Проверяем точное совпадение
        if word in terms_dict:
            explanations.append(f"{word}: {terms_dict[word]}")
        # Проверяем единственное число (убираем "ы", "и", "я")
        elif word.endswith(('ы', 'и', 'я')):
            singular = word[:-1]
            if singular in terms_dict:
                explanations.append(f"{word}: {terms_dict[singular]}")
        # Проверяем корень слова (упрощённая лемматизация)
        elif any(word.startswith(term) for term in terms_dict.keys()):
            for term in terms_dict.keys():
                if word.startswith(term):
                    explanations.append(f"{word}: {terms_dict[term]}")
    print(f"Проверяемые слова: {words}")
    return "\n".join(explanations) if explanations else "Сложные термины не найдены."

if __name__ == "__main__":
    text = sys.argv[1] if len(sys.argv) > 1 else ""
    if text:
        print(explain_terms(text))
    else:
        print("Ошибка: текст не передан.")
