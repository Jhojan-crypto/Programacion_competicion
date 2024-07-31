const trie = new Trie();
const phpKeywords = [
    "abstract", "and", "array", "as", "break", "callable", "case", "catch", "class",
    "clone", "const", "continue", "declare", "default", "do", "echo", "else", "elseif",
    "enddeclare", "endfor", "endforeach", "endif", "endswitch", "endwhile", "eval", "exit",
    "extends", "final", "finally", "for", "foreach", "function", "global", "goto", "if",
    "implements", "include", "include_once", "instanceof", "insteadof", "interface", "isset",
    "list", "namespace", "new", "or", "print", "private", "protected", "public", "require",
    "require_once", "return", "static", "switch", "throw", "trait", "try", "unset", "use",
    "var", "while", "xor", "yield"
];

// Insert PHP keywords trie
for (const keyword of phpKeywords) {
    trie.insert(keyword);
}

const searchInput = document.getElementById('search');
const suggestionsContainer = document.getElementById('suggestions');

let currentIndex = -1;

searchInput.addEventListener('input', () => {
    const query = searchInput.value;
    const lastWord = query.split(' ').pop();
    const suggestions = trie.autoComplete(lastWord);

    suggestionsContainer.innerHTML = '';
    currentIndex = -1;

    if (suggestions.length > 0) {
        suggestionsContainer.style.display = 'block';
        for (const suggestion of suggestions) {
            const suggestionElement = document.createElement('div');
            suggestionElement.className = 'suggestion';
            suggestionElement.textContent = suggestion;
            suggestionElement.addEventListener('click', () => {
                const words = searchInput.value.split(' ');
                words.pop();
                words.push(suggestion);
                searchInput.value = words.join(' ');
                suggestionsContainer.innerHTML = '';
                suggestionsContainer.style.display = 'none';
            });
            suggestionsContainer.appendChild(suggestionElement);
        }
    } else {
        suggestionsContainer.style.display = 'none';
    }
});

searchInput.addEventListener('keydown', (e) => {
    const suggestions = suggestionsContainer.getElementsByClassName('suggestion');
    if (e.key === 'ArrowDown') {
        currentIndex = (currentIndex + 1) % suggestions.length;
        highlightSuggestion(suggestions);
    } else if (e.key === 'ArrowUp') {
        currentIndex = (currentIndex - 1 + suggestions.length) % suggestions.length;
        highlightSuggestion(suggestions);
    } else if (e.key === 'Enter') {
        if (currentIndex >= 0 && currentIndex < suggestions.length) {
            const words = searchInput.value.split(' ');
            words.pop();
            words.push(suggestions[currentIndex].textContent);
            searchInput.value = words.join(' ');
            suggestionsContainer.innerHTML = '';
            suggestionsContainer.style.display = 'none';
        }
    }
});

function highlightSuggestion(suggestions) {
    for (let i = 0; i < suggestions.length; i++) {
        if (i === currentIndex) {
            suggestions[i].classList.add('active');
        } else {
            suggestions[i].classList.remove('active');
        }
    }
}
