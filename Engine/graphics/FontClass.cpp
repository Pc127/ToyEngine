#include "fontclass.h"


FontClass::FontClass()
{
	mFont = 0;
	mTexture = 0;
}


FontClass::FontClass(const FontClass& other)
{
}


FontClass::~FontClass()
{
}


bool FontClass::initialize(ID3D11Device* device, char* fontFilename, WCHAR* textureFilename)
{
	bool result;


	// Load in the text file containing the font data.
	result = loadFontData(fontFilename);
	if (!result)
	{
		return false;
	}

	// Load the texture that has the font characters on it.
	result = loadTexture(device, textureFilename);
	if (!result)
	{
		return false;
	}

	return true;
}


void FontClass::shutdown()
{
	// Release the font texture.
	releaseTexture();

	// Release the font data.
	releaseFontData();

	return;
}


bool FontClass::loadFontData(char* filename)
{
	ifstream fin;
	int i;
	char temp;


	// Create the font spacing buffer.
	mFont = new FontType[95];
	if (!mFont)
	{
		return false;
	}

	// Read in the font size and spacing between chars.
	fin.open(filename);
	if (fin.fail())
	{
		return false;
	}

	// Read in the 95 used ascii characters for text.
	for (i = 0; i<95; i++)
	{
		fin.get(temp);
		while (temp != ' ')
		{
			fin.get(temp);
		}
		fin.get(temp);
		while (temp != ' ')
		{
			fin.get(temp);
		}

		fin >> mFont[i].left;
		fin >> mFont[i].right;
		fin >> mFont[i].size;
	}

	// Close the file.
	fin.close();

	return true;
}


void FontClass::releaseFontData()
{
	// Release the font data array.
	if (mFont)
	{
		delete[] mFont;
		mFont = 0;
	}

	return;
}


bool FontClass::loadTexture(ID3D11Device* device, WCHAR* filename)
{
	bool result;


	// Create the texture object.
	mTexture = new TextureClass;
	if (!mTexture)
	{
		return false;
	}

	// Initialize the texture object.
	result = mTexture->Initialize(device, filename);
	if (!result)
	{
		return false;
	}

	return true;
}


void FontClass::releaseTexture()
{
	// Release the texture object.
	if (mTexture)
	{
		mTexture->Shutdown();
		delete mTexture;
		mTexture = 0;
	}

	return;
}


ID3D11ShaderResourceView* FontClass::getTexture()
{
	return mTexture->GetTexture();
}


void FontClass::buildVertexArray(void* vertices, char* sentence, float drawX, float drawY)
{
	VertexType* vertexPtr;
	int numLetters, index, i, letter;


	// Coerce the input vertices into a VertexType structure.
	vertexPtr = (VertexType*)vertices;

	// Get the number of letters in the sentence.
	numLetters = (int)strlen(sentence);

	// Initialize the index to the vertex array.
	index = 0;

	// Draw each letter onto a quad.
	for (i = 0; i<numLetters; i++)
	{
		letter = ((int)sentence[i]) - 32;

		// If the letter is a space then just move over three pixels.
		if (letter == 0)
		{
			drawX = drawX + 3.0f;
		}
		else
		{
			// First triangle in quad.
			vertexPtr[index].position = D3DXVECTOR3(drawX, drawY, 0.0f);  // Top left.
			vertexPtr[index].texture = D3DXVECTOR2(mFont[letter].left, 0.0f);
			index++;

			vertexPtr[index].position = D3DXVECTOR3((drawX + mFont[letter].size), (drawY - 16), 0.0f);  // Bottom right.
			vertexPtr[index].texture = D3DXVECTOR2(mFont[letter].right, 1.0f);
			index++;

			vertexPtr[index].position = D3DXVECTOR3(drawX, (drawY - 16), 0.0f);  // Bottom left.
			vertexPtr[index].texture = D3DXVECTOR2(mFont[letter].left, 1.0f);
			index++;

			// Second triangle in quad.
			vertexPtr[index].position = D3DXVECTOR3(drawX, drawY, 0.0f);  // Top left.
			vertexPtr[index].texture = D3DXVECTOR2(mFont[letter].left, 0.0f);
			index++;

			vertexPtr[index].position = D3DXVECTOR3(drawX + mFont[letter].size, drawY, 0.0f);  // Top right.
			vertexPtr[index].texture = D3DXVECTOR2(mFont[letter].right, 0.0f);
			index++;

			vertexPtr[index].position = D3DXVECTOR3((drawX + mFont[letter].size), (drawY - 16), 0.0f);  // Bottom right.
			vertexPtr[index].texture = D3DXVECTOR2(mFont[letter].right, 1.0f);
			index++;

			// Update the x location for drawing by the size of the letter and one pixel.
			drawX = drawX + mFont[letter].size + 1.0f;
		}
	}

	return;
}